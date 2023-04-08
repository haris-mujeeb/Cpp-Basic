/*

From Book: Oobject Oriented Programming C++ Simplified.

Experiment-8 : Write a program which illustrates the use of virtual base class.

*/

#include <iostream>
// #include <conio.h>

class student{
    char sname[20];
    int rollno;
public:
    void input_st(){
        std::cout << "Enter student name: ";
        std::cin.getline(sname, 20);
        std::cout << "Enter roll no: ";
        std::cin >> rollno;
        // std::cout << std::endl;
    }
    void show_st(){
        std::cout << "\tName := " << sname << std::endl;
        std::cout << "\tRoll Number := " << rollno << std::endl;
    }

};

class Subject : public student{
    char subject[25];
public: 
    void input_sub(){
        input_st();
        std::cin.ignore();
        std::cout << "Enter subject name: " << std::endl;
        std::cin.getline(subject, 25);
    }
    void show_sub(){
        show_st();
        std::cout << "\tSubject: " << subject << std::endl;
    }
};

class Internal : virtual public Subject{
    char subject[25];
protected:
    int i_marks = -1;
public:
    void input_im(){
        while(i_marks <0 || i_marks > 20){
            std::cout << "Enter internal marks (0-20): ";
            std::cin >> i_marks;
        };
    }
    void show_im(){
        std::cout << "\tInternal Marks: " << i_marks << std::endl;
    }
};

class External : virtual public Subject{
protected:
    int e_marks = -1;
public:
    void input_em(){
        while(e_marks <0 || e_marks > 20){
            std::cout << "Enter external marks (0-20): ";
            std::cin >> e_marks;
        };
    }
    void show_em(){
        std::cout << "\tExternal Marks: " << e_marks << std::endl;
    }
};

class Total : public Internal, public External{
    int total_marks;
public:
    void input(){
        input_sub();
        input_im();
        input_em();
    }
    void show(){
        show_sub();
        show_im();
        show_em();
        total_marks = i_marks + e_marks;
        std::cout << "\tTotal Marks: " << total_marks << std::endl;
    }
};

int main(){
    Total tm; 
    tm.input();
    std::cout << "\n\t ++++++++++Student Report++++++++\n"<< std::endl;
    tm.show();
    return 0;
}