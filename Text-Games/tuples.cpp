// Tuple is a class that can contain any x amount of variables
using namespace std;
#include <iostream>
#include <tuple> // for tuple


std:: tuple<double, char, std::string> get_student(int roll_number)
{
    if (roll_number == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson"); // initializing a tuple
    if (roll_number == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
    if (roll_number == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
    throw std::invalid_argument("id");
}


int main(){
    auto student0 = get_student(0); // assigning student 0 the value of the tuple from the funtion

    // assessing a tuple using "get<>()"
    std::cout << "ID:0, "<< "CGPA: " << get<0>(student0) << "," 
                << " grade: " << get<1>(student0) << ","
                << " name: " << get<2>(student0) << endl;

    // another way of assessing a tuple"
    double gpa1; char grade1; std::string name1;
    std:tie(gpa1, grade1, name1) = get_student(1);
    std::cout << "ID:1, "<< "CGPA: " << gpa1 << "," 
                << " grade: " << grade1 << ","
                << " name: " << name1 << endl;

    // using C++17 structred binding:
    auto [gpa2, grade2, name2] = get_student(2);
    std::cout << "ID:2, "<< "CGPA: " << gpa2 << "," 
                << " grade: " << grade2 << ","
                << " name: " << name2 << endl;
}