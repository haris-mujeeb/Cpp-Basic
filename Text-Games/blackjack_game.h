#ifndef Blackjack_game_H
#define Blackjack_game_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

class Card
{
public:
    enum rank { ACE= 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, 
                    JOKER, QUEEN, KING};
    enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
    friend ostream& operator<<(ostream& os, const Card& aCard);
    Card(rank r, suit s, bool isFaceUp = true);
    ~Card();
    int GetValue() const;   // return the value of the card
    void Flip();            // flips a card, Face up becomes face down and vise versa.
private:
    rank m_Rank;
    suit m_Suit;
    bool m_isFaceUp;

};
ostream& operator<<(ostream& os, const Card& aCard){
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if(aCard.m_isFaceUp){
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else{
        os << "XX";
    }
    return os;
}
Card::Card(rank r, suit s, bool isFaceUp) : m_Rank(r), m_Suit(s), m_isFaceUp(isFaceUp)
{}
Card::~Card()
{}
int Card::GetValue() const {
    if (m_isFaceUp)
        return m_Rank;
    return 0;       // if a card is face down, its value is 0
}
void Card::Flip(){
    m_isFaceUp = !m_isFaceUp;
}


class Hand
{
protected:
    vector<Card*> m_Cards; // Collection of cards. Stores pointers to Card objects.
public:
    Hand();
    virtual ~Hand();
    void Add(Card* pCard);  // Adds a card to the hand. Adds a pointer to Card to the vector m_Cards.
    void Clear();           // Clears alll cards from the hand. Removes all pointers in the vector m_Card,
                            // deleting all associated Card objects on the heap.
    int GetTotal() const;   // Returns the total value of the hand.
};
Hand::Hand()
{
    m_Cards.reserve(7);
}
Hand::~Hand()
{
    Clear();
}
void Hand::Add(Card* pCard){
    m_Cards.push_back(pCard); 
}
void Hand::Clear(){
    for (Card* pCard : m_Cards){  // C++11 introduced this type of "range based for loop" for containers (like, std::vector)
        delete pCard;  
        pCard = 0;
    }
    m_Cards.clear();
}
int Hand::GetTotal() const{
    if (m_Cards.empty())
        return 0;

    int total = 0;
    bool containsAce = 0;
    for (Card* pCard : m_Cards){
        total += (pCard->GetValue());
        if (pCard->GetValue() == Card::ACE)
            containsAce = 1;
    }
    if (containsAce == 1 && total <= 11) total += 10; // add only 10 since we've already added 1 for the ace
    return total;
}


class GenericPlayer : public Hand
{
    friend ostream& operator<< (ostream& os, const GenericPlayer& aGenericPlayer);
    protected:
        string m_Name;      // Name of the Generic Player.
    public:
        GenericPlayer (const string& name = "");
        virtual ~GenericPlayer ();
        virtual bool IsHitting() const = 0;     // Indicates whether the generic player wants another hit. Pure virual function
        bool IsBusted() const;        // indicates whether the generic player is busted or not.
        void Bust() const;      // Announces that the generic plater is busts
};
ostream& operator<< (ostream& os, const GenericPlayer& aGenericPlayer){
    os << aGenericPlayer.m_Name << ": \t";
    std::vector<Card*>::const_iterator pCard;  // const_iterator points to a iterator with constant value. Prevents modification.
    if(!aGenericPlayer.m_Cards.empty()){
        for(pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); pCard++){
            os << **pCard << "\t";
        }
        if(aGenericPlayer.GetTotal() != 0)  os << "(" << aGenericPlayer.GetTotal() << ")";
    }
    else{
        os << "<empty>";
    }
    return os;
}
GenericPlayer::GenericPlayer(const string& name)
{
    this->m_Name = name;
}
GenericPlayer::~GenericPlayer()
{
}
bool GenericPlayer::IsBusted() const{
    return (GetTotal() > 21);
}
void GenericPlayer::Bust() const{
    cout << std::endl  << "Player: "<< m_Name << " is busted!";
}

class Player : public GenericPlayer
{
public:
    Player(const string& name = "");
    virtual ~Player();
    bool IsHitting() const; // Indicated whether the player is hitting or not.
    void Win() const;       // announces that the player wins.
    void Lose() const;      // announces that the player loses.
    void Push() const;      // announces that the player pushes.
};
Player::Player(const string& name):
    GenericPlayer(name)
{}
Player::~Player()
{}
bool Player::IsHitting() const{
    char input = 'n';
    cout << "Do you want a hit? (y/n): ";
    cin >> input;
    return (input == 'y' || input == 'Y');
}
void Player::Win() const{
    cout << std::endl <<"Player: "<< m_Name << " won!";
}
void Player::Lose() const{
    cout << std::endl << "Player: "<< m_Name << " lost!";
}
void Player::Push() const{
    cout << std::endl  << "Player: "<< m_Name << " pushes.";
}

class House : public GenericPlayer
{
public:
    House(const string& name = "House");
    virtual ~House();
    virtual bool IsHitting() const; // indicates whether house is hitting - will always hit on 16 or less
    void FlipFirstCard();           //flips over first card
};
House::House(const string& name):
    GenericPlayer(name)
{}
House::~House()
{}
bool House::IsHitting() const{
    return (GetTotal() <= 16);
}
void House::FlipFirstCard(){
    if (!(m_Cards.empty()))    
        m_Cards[0]->Flip();
    else
        cout << "No cards to flip!" << endl;
}


class Deck : public Hand
{
public:
    Deck();
    virtual ~Deck();
    void Populate();        // Creates a standard deck of 52 cards
    void Shuffle();         // Shuffles the cards.
    void Deal(Hand& aHand); // Deals one card to a hand.
    void AdditionalCards(GenericPlayer& aGenericPlayer);    // gives additional cards to generic players,
                                                            // for as long as the generic player can and wants to hit.
};
Deck::Deck()
{
    m_Cards.reserve(52);
    Populate();
}
Deck::~Deck()
{}
void Deck::Populate(){
    Clear();
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s){
        for(int r = Card::ACE; r <= Card::KING; ++r){
            Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
        }
    }
}
void Deck::Shuffle(){
    random_shuffle(m_Cards.begin(), m_Cards.end());
}
void Deck::Deal(Hand& aHand){
    if(!m_Cards.empty()){
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    else {
        cout << "Out of cards. Unable to deal.";
    }
}
void Deck::AdditionalCards(GenericPlayer& aGenericPlayer){
    cout << endl;
    while((!aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting()){
        Deal(aGenericPlayer);
        cout << aGenericPlayer << endl;
        if(aGenericPlayer.IsBusted()) 
            aGenericPlayer.Bust();
    }
}

class Game
{
    private:
        Deck m_Deck;    // An instance of Deck of cards.
        House m_House;  // An instance of House / Casino's hand.
        vector<Player> m_Players; // Collection of Human Players.
    public:
        Game(const vector<string>& names);
        virtual ~Game();
    void Play();        // Plays a round of Blackjack.
};
Game::Game(const vector<string>& names)
{
//    for(vector<string>::const_iterator pName = names.begin(); pName != names.end(); ++pName)
    for(auto pName : names) // alternative of above line of code for iteration.
        m_Players.push_back(Player(pName));
    srand(static_cast<unsigned int>(time(0))); // seed the random number generator.
    m_Deck.Shuffle();
}
Game::~Game()
{
}

void Game::Play(){
// Deal players and the house two initial cards
    vector<Player>::iterator pPlayer;
    for (int i= 0; i<2 ; i++){
        for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
            m_Deck.Deal(*pPlayer);
        }
        m_Deck.Deal(m_House);
    }
// Hide the house's first card
    m_House.FlipFirstCard();
//Display player's and house's hands
    for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
        cout << *pPlayer << endl;
    }
    cout << m_House <<endl;
// Deal additional cards to players
    for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++) {
        m_Deck.AdditionalCards(*pPlayer);
    }
// Reveal house's first card
    m_House.FlipFirstCard();
    cout << endl << m_House;
// Deal additional cards to house
    m_Deck.AdditionalCards(m_House);

    if(m_House.IsBusted()){// If house is busted
        for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++){//  Everyone who is not busted wins
            if(!(pPlayer->IsBusted())){
                pPlayer->Win();
            }
        }
    }
    else{
        for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++){//      For each player
            if(!(pPlayer->IsBusted())){
                if(pPlayer->GetTotal() > m_House.GetTotal()){//          If player's total is greater than house's total
                    pPlayer->Win();//              player wins
                }
                else if(pPlayer->GetTotal() < m_House.GetTotal()){//          else if player's total is less than house's total
                    pPlayer->Lose();//              player loses
                }
                else{//          otherwise
                    pPlayer->Push();//              player pushes
                }
            }

        }
    }

    //      Remove everyone's cards
     for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++){
        pPlayer->Clear();
     }
     m_House.Clear();
}

#endif