// Critter Farm

#include <iostream>
#include <vector>

using namespace std;


class Critter{
    friend void Peek(const Critter& aCritter); // making a global friend function of the Critter class
    friend ostream& operator<<(ostream& os, const Critter& aCritter);
    public:
        Critter(const string& name = "");
        string GetName() const;
    private:
        string m_Name;
};

Critter::Critter(const string& name):
    m_Name(name)
    {}

inline string Critter::GetName() const {
    return m_Name;
    }

// protoype of friend function Peek() 
void Peek(const Critter& aCritter);
ostream& operator << (ostream& os, const Critter& aCritter);


// Farm class
class Farm
{
public:
    Farm(int spaces = 1);
    void Add(const Critter& aCritter);
    void RollCall() const;
private:
    vector<Critter> m_Critter;
};

Farm::Farm(int spaces){
    m_Critter.reserve(spaces);
}

void Farm::Add(const Critter& aCritter){
    m_Critter.push_back(aCritter);
}

void Farm::RollCall() const{

    for (vector<Critter>::const_iterator iter = m_Critter.begin();
            iter != m_Critter.end(); ++iter){
        cout<< iter->GetName() << " here.\n";
    }
}

// main fucntion

int main(){
    // add "Poochie"
    Critter crit("Poochie");
    cout << "My critter's name is " << crit.GetName() << endl;     
    
    // create Farm
    Farm farm(3);

    // add "Moe" "larrt" "Curly" to the farm
    farm.Add(Critter("Moe"));
    farm.Add(Critter("Larrt"));
    farm.Add(Critter("Curly"));
    
    // roll call
    farm.RollCall();

    Peek(crit);
    cout << "\nSending crit object to cout with the operator: \n";
    cout << crit;

// a default value 0 is returned in main if no value is return
}

// global friend function that can acess all of a Critter's objects members
void Peek(const Critter& aCritter){
    cout << aCritter.m_Name << endl;
}

// overloads the << operator so you can send a Critter object to cout 
ostream& operator<<(ostream& os, const Critter& aCritter){
    os << "Critter Object - ";
    os << "m_Name: " << aCritter.m_Name;
    return os;
}