/*
From Book: Oobject Oriented Programming C++ Simplified.

Experiment-1 : Program illustrating function overloading feature.

Experiment-2 Programs illustrating the overloading of various operators. 
    Ex : Binary operators, Unary operators, New and delete operators, etc.

*/

#include <iostream>
// #include <conio.h>

class demo_exp{
    friend std::ostream& operator<< (std::ostream& os, const demo_exp& obj);
    friend std::istream& operator>> (std::istream& os, demo_exp& obj);
        float num;
    public:
        demo_exp operator + (demo_exp obj_){ 
            demo_exp temp;
            temp.num = num + obj_.num;
            return temp;   
        }
        demo_exp operator - (demo_exp obj_){ 
            demo_exp temp;
            temp.num = num - obj_.num;
            return temp;  
        }
        demo_exp operator * (demo_exp obj_){ 
            demo_exp temp;
            temp.num = num * obj_.num;
            return temp;   
        }
        demo_exp operator / (demo_exp obj_){ 
            demo_exp temp;
            temp.num = num / obj_.num;
            return temp;   
        }
        demo_exp operator ++ (int){ 
            num++;
            return *this;   
        };

        demo_exp operator -- (int){ 
            num --;
            return *this;   
        };
};
std::ostream& operator<< (std::ostream& os, const demo_exp& obj){
    os << obj.num;
    return os; 
}

std::istream& operator>> (std::istream& is, demo_exp& obj){
    is >> obj.num;
    return is; 
}

int main(){

    demo_exp obj1;
    demo_exp obj2;
    demo_exp obj3;
    demo_exp obj4;

    std::cout << "Enter obj1: ";
    std::cin >> obj1;
    std::cout << "Enter obj2: ";
    std::cin >> obj2;
    std::cout << "\n obj1: " << obj1;
    std::cout << "\n obj2: " << obj2;

    obj3 = obj1 + obj2 - obj1 * obj2 / obj1;
    std::cout << "\n \n obj3 = obj1 + obj2  - obj1 * obj2 / obj1 : "<< obj3;
    
    obj4 = obj3++;
    std::cout << "\n \n obj4 = obj4 = obj3++ : "<< obj4;
    
    obj4 = obj3--;
    std::cout << "\n \n obj4 = obj4 = obj3-- : "<< obj4;
}