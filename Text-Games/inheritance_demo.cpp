// Simple Boss

#include <iostream>
using namespace std;

class Enemy
{
public: // public modifier means these members are accessible to all code in the program.
    Enemy();
    void Attack() const;    // / this const promises not to modify the members used in the Enemy class.
    void virtual Taunt() const; // virtual keyword is used for override base class member function by derived class.
protected:  // protected modifier means these members are accessible only in their own class and (certain) derived class.
    int m_Damage;
};

Enemy::Enemy():
    m_Damage(10)
    {}

void Enemy::Attack() const {    // this const promises not to modify the members used in the Enemy class.
    cout << "Attack inflicts " << m_Damage << " damage points." << endl;
}

void Enemy::Taunt() const{
    cout << "The enemy says he will fight you." << endl;
}



class Boss : public Enemy
{
public:
    Boss();
    void SpecialAttack() const;
    void virtual Taunt() const; // keyword Virtual here is optional.
private:    // private modifier means these members are accessible only to this class itself,
            // (not accessible in any derived class).
    int m_DamageMultiplier;
};

Boss::Boss():
    m_DamageMultiplier(3)
    {}

void Boss::SpecialAttack() const {    // this const promises not to modify the members used in the Enemy class.
    cout << "Special Attack inflicts " << m_DamageMultiplier * m_Damage << " damage points." << endl;
}

void Boss::Taunt() const{
    cout << "The boss says he will end your pitiful existence." << endl;
}


int main(){
    Enemy enemy1;
    enemy1.Taunt();
    enemy1.Attack();

    Boss boss1;
    boss1.Taunt();
    boss1.Attack();
    boss1.SpecialAttack();

    return 0;
}