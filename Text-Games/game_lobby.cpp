#include <iostream>

using namespace std;

class Player
{
private:
    string m_Name;
    Player* m_pNextPlayer;
public:
    Player(const string& name = "");
    string GetName() const;
    Player* GetNextPlayer() const;
    void SetNextPlayer(Player* next);
};

Player::Player(const string& name):
    m_Name(name), m_pNextPlayer(0)
  {}
  

string Player::GetName() const
{
    return m_Name;
}

Player* Player::GetNextPlayer() const
{
    return m_pNextPlayer;
}

void Player::SetNextPlayer(Player* next)
{
    m_pNextPlayer = next;
}

class Lobby
{
    friend ostream& operator<<(ostream& os, const Lobby& aLobby);
private:
    Player* m_pHead;
public:
    Lobby();
    ~Lobby();
    void AddPlayer();
    void RemovePlayer();
    void Clear();
};

Lobby::Lobby():
    m_pHead(0)   // initiallizing the Lobby class.
{}

Lobby::~Lobby()
{
    Clear();
}

void Lobby::AddPlayer()
{
    cout << "Please enter the name of the new player: ";
    string name;
    cin >> name;
    Player* pNewPlayer = new Player(name);

    // if list is empty, 
    if (m_pHead == 0)
    {
        m_pHead = pNewPlayer; // make head of list this new player
    }
    //otherwise 
    else
    {
        Player* pIter = m_pHead;
        while (pIter->GetNextPlayer() != 0) // find the end of the list
        {
            pIter = pIter->GetNextPlayer();
        }
        pIter -> SetNextPlayer(pNewPlayer); // and add the player there
    }
}

void Lobby::RemovePlayer()
{   
    if (m_pHead == 0) cout << "The game lobby is empty. No one to remove! \n"; 
    else    // removes the player at the head of the line.
    {
        Player* pTemp = m_pHead;
        m_pHead = m_pHead -> GetNextPlayer();
        delete pTemp;
    }
}

void Lobby::Clear()
{
    while (m_pHead !=0)
    {
        RemovePlayer();
    }
}

ostream& operator<<(ostream& os, const Lobby& aLobby)
{
    Player* pIter = aLobby.m_pHead;
    os << "\n Here is who is in the Lobby: "<< endl;
    if (pIter == 0) os << "The Lobby is empty." << endl;
    else
    {
        while (pIter != 0)
        {
            os << pIter ->GetName() << endl;
            pIter = pIter->GetNextPlayer();
        }
        
    }
    return os;
}

int main()
{
    Lobby myLobby;
    int choice;

    do 
    {
        cout << myLobby;
        cout << endl << "-------- Game Lobby --------" << endl;
        cout << "0 - Exit the program.\n";
        cout << "1 - Add a player to the lobby.\n";
        cout << "2 - Remove a player from the lobby.\n";
        cout << "3 - Clear the lobby.\n";
        cout << endl << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0: cout << "Goodbye!"<< endl;break;
        case 1: myLobby.AddPlayer(); break;
        case 2: myLobby.RemovePlayer(); break;
        case 3: myLobby.Clear(); break;
        default: cout << "That was not a valid choice"; break;
        }
    }while (choice != 0);
    return 0;
}