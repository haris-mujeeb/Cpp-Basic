 // preprocessor statement  
// anything with # is called a preprocessor directive
#include <iostream> // include preprocessor statements will find a file called "iostream", 
                    // take all the content of that file and paste it in this file
                    // we use <> for standard file while using include
                    // we use "" for local file while using include

int main(){ // main function is the entry point for our program
    std::cout << ""Hello, world!" << std::endl; // here "<<" is the overloaded operator
               // operators are just functions in the back end
}

// A linker links all the obj files (compiled cpp files) into an exe file