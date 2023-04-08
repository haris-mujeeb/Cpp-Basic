#include <iostream>
#include <vector>
using namespace std;


// ------ Funtions used in References Examples ---------
void swap(int var1, int var2);
void swap2(int &var1, int &var2);
void display(const vector<string>& vec);

// ------ Funtions used in Pointers Examples ---------
void badSwap(int x, int y);
void goodSwap(int* const pX, int* const pY);
string* ptrToElement(vector<string>* const pVec, int i);
void increase(int* const array, const int NUM_ELEMENTS);
void display_array(const int* const array, const int NUM_ELEMENTS);
// --------------------------------------------------

int main(){
// ------- References -------------------
    int var1 = 1;
    int var2 = 2;
    cout << var1 << var2 <<endl;
    swap(var1, var2);
    cout << var1 << var2 <<endl;
    swap2(var1, var2);
    cout << var1 << var2 <<endl;

    vector<string> inventory = {"sword", "armor", "shield"}; // this assignment is possible in new versions of C++
    display(inventory);


// ------- Pointers -------------------
    int* pAPointer;     //declaring a pointer
    int* pScore = 0;    //declare and initialize a pointer
    int score = 1000;   
    pScore = &score;    // assign pointer pScore address of variable score
    cout<<"Assigning &score to pScore\n";
    cout<<"&score is: "<< &score << endl;    // address of score variable
    cout<<"pScore is: "<< pScore << endl;    // address stored in pointer
    cout<<"score is: "<< score << "\n";     
    cout<<"*pScore is: "<< *pScore << "\n"; // value pointed to by pointer
    
    cout<<"Adding 500 to score\n";
    score += 500;
    cout<<"score is: "<< score << "\n";     
    cout<<"*pScore is: "<< *pScore << "\n"; // value pointed to by pointer
    
    cout<<"Adding 500 to *pScore\n";
    *pScore += 500;
    cout<<"score is: "<< score << "\n";     
    cout<<"*pScore is: "<< *pScore << "\n"; // value pointed to by pointer
    
    cout<<"Assigning &newScore to pScore\n";
    int newScore = 5000;
    pScore = &newScore;
    cout<<"&newScore is: "<< &newScore << "\n";     
    cout<<"pScore is: "<< pScore << "\n"; 
    cout<<"newScore is: "<< newScore << "\n";     
    cout<<"*pScore is: "<< *pScore << "\n"; 

    cout<<"Assigning &str to pStr \n";
    string str = "score";
    string* pStr = &str;    //pointer to string object
    cout<< "str is: "<< str << '\n';
    cout<< "*pStr is: "<< *pStr << "\n";
    cout<< "(*pStr).size() is: "<< (*pStr).size()<< endl;
    cout<< "pStr->size() is: "<< pStr->size() << '\n';

// --------- Swapping using Pointers ----------------
    int myScore = 150;
    int yourScore = 1000;
    cout << "Original values" << endl;
    cout << "myScore: " << myScore << endl;
    cout << "yourScore: " << yourScore << endl;
    
    cout << "Calling badSwap()"<< endl;
    badSwap(myScore, yourScore);
    cout << "myScore: " << myScore << endl;
    cout << "yourScore: " << yourScore << endl;
    
    cout << "Calling goodSwap()"<< endl;
    goodSwap(&myScore, &yourScore);
    cout << "myScore: " << myScore << endl;
    cout << "yourScore: " << yourScore << endl;
    
// ----- Returning Pointers -------------

    // displays string object of the returned pointer from funtion ptrToElement()
    cout << "Sending the object pointed to by returned pointer to cout:\n";
    cout << *(ptrToElement(&inventory, 0)) << endl << endl;

    cout << "Assigning the returned pointer to another pointer.\n";
    string* pString = ptrToElement(&inventory, 1);

    cout << "Sending the object pointed to by new pointer to cout:\n";
    cout << *pString << endl << endl;

    // copies a sting object -- expensive assignment
    cout << "Assignment object pointed by a pointer to a string object." << endl;
    string string = *(ptrToElement(&inventory, 2));
    cout << "Sending the new string object to cout: " << endl;
    cout << string << endl;

    // altering the string object through a returned pointer
    cout << "Altering an object through a returned pointer." << endl;
    *pString = "Healing Potion"; 
    cout << "Sending the alter object to cout: "<< endl;
    cout << inventory[1] << endl;

// ------ Array Passer ------------
    cout << "Creating an array of high scores.\n\n";
    const int NUM_SCORES = 3;
    int highScores[NUM_SCORES] = {5000, 3500, 2700};
    
    cout << "Displaying scores using array name as a constant pointer." << endl;
    cout << *highScores << endl;
    cout << *(highScores + 1) << endl;
    cout << *(highScores + 2) << endl << endl;

    cout << "Increasing scores by passing array as a constant pointer.\n\n";
    increase(highScores, NUM_SCORES);
    
    cout << "Displaying scores by passing array as a constant pointer to a constant . \n" ;
    display_array(highScores, NUM_SCORES);
    return 0;
}

// ------ Funtions used in References Examples ---------
void swap(int var1, int var2){
    int temp = var1;
    var1 = var2;
    var2 = temp;
}

void swap2(int &var1, int &var2){
    int temp = var1;
    var1 = var2;
    var2 = temp;
}

void display(const vector<string>& vec){
    cout << "Your items:\n";
    for (vector<string>::const_iterator iter = vec.begin(); 
            iter != vec.end(); ++iter){
        cout << *iter << endl;
    }
}

// ------ Funtions used in Pointers Examples ---------
void badSwap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

void goodSwap(int* const pX, int* const pY){
    // store value pointed to by pX in temp
    int temp = *pX;
    *pX = *pY;
    *pY = temp;
}

string* ptrToElement(vector<string>* const pVec, int i){
    // returns address of the string in position i of vector that pVec points to
    return &((*pVec)[i]);
}

void increase(int* const array, const int NUM_ELEMENTS){
    for (int i=0; i<NUM_ELEMENTS; i++){
        array[i] += 500;
    }
}


void display_array(const int* const array, const int NUM_ELEMENTS){
    for (int i = 0; i <NUM_ELEMENTS; i++){
        cout << array[i]<< endl;
    }
}
