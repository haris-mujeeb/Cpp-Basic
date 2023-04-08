// Simple Critter
// Demonstrates creating a new type

#include <iostream>

using namespace std;

class Critter{      // class definition -- defines a new type,
    public:         // begin public section
        static int s_Total; // static member variable declaration
                            // total number of Critter objects in existence
        Critter(int hunger = 0); // constructor prototype
        void Greet();   // member function prototype
        int GetHunger() const;
        void SetHunger(int hunger);
        static int GetTotal(); // static member function prototype
        
    private:            // begin private section
        int m_Hunger;   // data member
};

int Critter::s_Total = 0;       // static member variable initialization

Critter::Critter(int hunger):   // constructor defination
    m_Hunger(hunger)            // using member initialization shortcut
    {
        cout << "A new critter has been born!" << endl;
        ++s_Total;
    }

void Critter::Greet(){   // member function definition
    cout << "Hi. I'm a critter. My hunger level is " << m_Hunger << endl;
}

int Critter::GetHunger() const{
    return m_Hunger;
}

void Critter::SetHunger(int hunger){
    if (hunger < 0){
        cout << "You can't set a critter's hunger to a negative number." << endl << endl;
    }
    else m_Hunger = hunger;
}

int Critter::GetTotal(){ /// static member function definition
    return s_Total;
}


int main(){
    Critter crit1;
    Critter crit2;

    // crit1.m_Hunger = 9; // illegal, m_Hunger is private
    crit1.SetHunger(9);
    cout << "crit1's hunger level is " << crit1.GetHunger() << endl;

    crit2.SetHunger(3);
    cout << "crit2's hunger level is " << crit2.GetHunger() << endl << endl;
    
    Critter crit3(7);
    cout << "crit3's hunger level is " << crit3.GetHunger() << endl << endl;

    Critter crit4(5);
    // cout << crit4.m_Hunger; // illegal, m_hunger is private
    cout << "Calling GetHunger(): "<< crit4.GetHunger() << endl<< endl;

    cout << "Calling SetHunger() with -1" << endl;
    crit4.SetHunger(-1);

    cout << "Calling SetHunger() with 9.\n";
    crit4.SetHunger(9);
    cout << "Calling GetHunger(): "<< crit4.GetHunger() << "\n\n";


    crit1.Greet();
    crit2.Greet();
    crit3.Greet();
    crit4.Greet();

    cout << endl << "The total number of critters is: ";
    cout << Critter::GetTotal() << endl;

    return 0;
}