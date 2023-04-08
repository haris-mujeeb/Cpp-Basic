/*
From Book: Oobject Oriented Programming C++ Simplified.

Experiment-3 : Programs illustrating the use of following functions.
                    (a) Friend functions
                    (b) Inline functions
*/

#include <iostream>
// #include <conio.h>

class second;
class first{
        float x;
    public:
        friend std::istream& operator>> (std::istream& is, first& obj){
            is >> obj.x;
            return is;
        }
        friend std::ostream& operator<< (std::ostream& os, const first& obj){
            os << obj.x;
            return os; 
        }
        friend float findMax(first&, second&);
        friend void swap(first& f, second& s);
            
};

class second{
        float x;
    public:
        friend std::istream& operator>> (std::istream& is, second& obj){
            is >> obj.x;
            return is;
        }
        friend std::ostream& operator<< (std::ostream& os, const second& obj){
            os << obj.x;
            return os; 
        }
        friend float findMax(first& f, second& s);
        friend void swap(first& f, second& s);
};

inline float findMax(first& f, second& s){  // inline function
    return (f.x > s.x) ? f.x : s.x; 
}
        
void swap(first& f, second& s){
    first f_temp = f;
    f.x = s.x;
    s.x = f_temp.x;
}


int main(){

    first f;
    second s;

    std::cout << "Enter obj1: ";
    std::cin >> f;
    std::cout << "Enter obj2: ";
    std::cin >> s;
    std::cout << "\n obj1: " << f;
    std::cout << "\n obj2: " << s;
    
    std::cout << "\n \nfindMax(f, s) = " << findMax(f, s);

    std::cout << "\n \ncalling swap() ... ";
    swap(f, s);
    std::cout << "\n obj1: " << f;
    std::cout << "\n obj2: " << s;

    // obj3 = obj1 + obj2 - obj1 * obj2 / obj1;
    // std::cout << "\n \n obj3 = obj1 + obj2  - obj1 * obj2 / obj1 : "<< obj3;
    
    // obj4 = obj3++;
    // std::cout << "\n \n obj4 = obj4 = obj3++ : "<< obj4;
    
    // obj4 = obj3--;
    // std::cout << "\n \n obj4 = obj4 = obj3-- : "<< obj4;
}