#include <iostream>
using namespace std;

class Enemy{
public: 
    Enemy(int damage = 10);
    virtual ~Enemy();   // allowing derived class constructors to be able to call their own destructors.
                        // otherwise derived class’ destructor might not be called.
    void virtual Attack() const;    // allowing polymorphism 

protected:
    int* m_pDamage;
};

Enemy::Enemy(int damage){
    m_pDamage = new int(damage);    //  dynamically allocates one object of type int and initialize it to value 'damage'
                                    // 'new' returns a prvalue pointer to the constructed object
}

Enemy::~Enemy(){
    cout << "In Enemy destructor, deleting m_pDamage./n";
    delete m_pDamage;
    m_pDamage = 0;
}

void Enemy::Attack() const{
    cout << "An enemy attacks and inflicts " << *m_pDamage << " damage points.";
}

class Boss : public Enemy{
public: 
    Boss(int multiplier = 10);
    virtual ~Boss();
    void virtual Attack() const;

protected:
    int* m_pMultiplier;
};

Boss::Boss(int multiplier){
    m_pMultiplier = new int(multiplier);    //  dynamically allocates one object of type int and initialize it to value 'multiplier'
                                             // 'new' returns a prvalue pointer to the constructed object
}

Boss::~Boss(){
    cout << "In Boss destructor, deleting m_pMultiplier./n";
    delete m_pMultiplier;
    m_pMultiplier = 0;
}

void Boss::Attack() const{
    cout << "A boss attacks and inflicts " << (*m_pDamage)*(*m_pMultiplier) << " damage points.";
}

int main(){
    cout << "Calling Attack() on Boss object through pointer to Enemy: \n";
    Enemy* pBadGuy = new Boss();

    pBadGuy->Attack(); // an alternative to:   (*pBadGuy).Attack();


    cout << "\n\nDeleting pointer to Enemy." << endl;
    delete pBadGuy;
    pBadGuy = 0;

    return 0;
}