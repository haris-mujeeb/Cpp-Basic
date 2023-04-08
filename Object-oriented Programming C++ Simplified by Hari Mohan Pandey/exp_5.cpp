/*
From Book: Oobject Oriented Programming C++ Simplified.

Experiment-5 : Programs illustrating the use of destructor and the various types of
constructors: 
        1. Constructor with no arguments
        2. Constructors with arguments
        3. Copy constructor etc.    

*/

#include <iostream>

class demo{
    int data;
public:
    demo();
    demo(int d):data(d){};
    demo(demo& demo_):data(demo_.data){};   // copy constructor.
};