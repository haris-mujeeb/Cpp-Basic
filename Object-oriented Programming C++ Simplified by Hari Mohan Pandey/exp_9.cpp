/*

From Book: Oobject Oriented Programming C++ Simplified.

Experiment-9 : Write a program which uses the following sorting methods for sorting
elements in ascending order. Use function templates :
        (a) Bubble sort
        (b) Selection sort
        (c) Quick sort.

*/

#include <iostream>

template< typename T>
 void bubble_sort(T array[], int len){
    for (T j = 0; j<len-1; j++){ 
        T temp;  
        for (int i = 0; i<len-1; i++){
            if (array[i] > array[i+1]) {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
}

template< typename T>
void selection_sort(T array[], int len){
    int pos_min;
    T temp;
    for (int j = 0; j<len-1; j++){ 
        pos_min = j;  
        for (int i = j; i<len; i++){
            if (array[i] < array[pos_min]) pos_min = i;
        }
        temp = array[j];
        array[j] = array[pos_min];
        array[pos_min] = temp;
    }
}


int main(){
    int len = 10 ;
    int array[len];
    for (int i=0; i < len; i++) array[i] = len -1 -i;
    
    for (int i=0; i<len; i++) std::cout << array[i]; 
    std::cout << std::endl;

    // bubble_sort(array,len);
    selection_sort(array,len);



    for (int i=0; i<len; i++) std::cout << array[i]; 
    std::cout << std::endl;
}