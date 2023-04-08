// Heap 
// Demonstrates dynamics alllocating memory

#include <iostream>
using namespace std;

int* intOnHeap();   // returns an int on the heap
void leak1();       // creates a memory leaks
void leak2();       // creates another memory leak

int main(){
    int* pHeap = new int;
    *pHeap = 10;
    cout << "*pHeap: " << *pHeap << endl << endl;
    
    int* pHeap2 = intOnHeap();
    cout << "*pHeap: " << *pHeap << endl << endl;

    cout << "freeing memory pointed by pHeap." << endl <<endl;
    delete pHeap;

    cout << "Freeing memory pointed by pHeap2." << endl << endl;
    delete pHeap2;

}

int* intOnHeap(){
    int* pTemp = new int(20);
    return pTemp;
}

void leak1(){
    int* drip1 = new int(30);
}

void leak2(){
    int* drip2 = new int(50);
    drip2 = new int(100);
    delete drip2;
}