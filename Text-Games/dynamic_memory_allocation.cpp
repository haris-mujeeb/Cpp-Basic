/* Write a C++ program that will test five functions described below that use pointers and dynamic memory allocation. 
The Functions: You will write the five functions described below.  
Then you will call them from the main function, to demonstrate their correctness. */

using namespace std;
#include <iostream>
/*1. maximum: takes an int array and the array's size as arguments.  
    It should return the maximum value of the array elements.  
    Do not use square brackets ANYWHERE in the function (use pointers instead).  

    Extra challenge: Do not use the loop variable in the body of the loop.  
*/
int maximun(int*p_array, size_t size){
    int max = *p_array;
    for(size_t i = 1; i < size; i++){
       if(*(p_array+i) > max) 
            max = *(p_array+i);
    }
    return max;
}

/*
2. oddSwap: The following function uses reference parameters. Rewrite the function so it uses pointers instead of reference variables.  
When you test this function from the main program, demonstrate that it changes the values of the variables passed into it. 

int oddSwap (int &x, int &y) {   
    int temp = x;   
    x = y * 5;   
    y = temp * 5;   
    return x + y; 
}
*/
int oddSwap(int *x, int *y){
    int temp = *x;
    *x = *y * 5;
    *y = temp * 5;
    return *x + *y;
}

/*
3. expand: takes an int array and the array's size as arguments. 
It should create a new array that is twice the size of the argument array.  
The function should copy the contents of the argument array to the new array, 
and initialize the unused elements of the new array with -1.  
The function should return a pointer to the new array.
*/
int* expand(int array[], size_t size){
    // the data defined on stack is automatically removed when varibale goes out of scope,
    // therefore defining a new array on heap to manually take care of the memory life cycle.
    int* new_array = new int [size*2]; // defining on heap instead of stack.
    for(size_t i =0; i<=size; i++){
        new_array[i] = *(array + i);
    }
    for(size_t i =size; i<=size*2; i++){
        new_array [i] = -1;
    }
    return new_array;
}

/*
4. concatenate: takes two int arrays and the arrays' sizes as arguments (that's 4 arguments).  
It should create a new array big enough to store both arrays.  
Then it should copy the contents of the first array to the new array, 
and then copy the contents of the second array to the new array in the remaining elements, 
and return a pointer to the new array. 
*/
void concat(int array_1[], size_t size_1, int array_2[], size_t size_2, int new_array[]){
    for(size_t i=0; i < size_1; i++) *(new_array + i) = *(array_1 + i);
    for(size_t i=0; i < size_2; i++) *(new_array + size_1 + i) = *(array_2 + i);
}


/*
5. subArray: Define subArray as follows: 
int *subArray (int *array, int start, int length) 
{ return duplicateArray(__________, ___________); } 
Add the code for duplicateArray from the lecture slides for chapter 9 (slide 24).  Fill in the blanks with expressions so that the function subArray behaves as follows: It takes an int array, a start index and a length as arguments.  It creates a new array that is a copy of the elements from the original array starting at the start index, and has length equal to the length argument.  For example, subArray(aa,5,4) would return a new array containing only the elements aa[5], aa[6], aa[7], and aa[8].  
DO NOT alter duplicateArray, DO NOT alter subArray as defined above.
*/
int * subArray(int *array, int start, int length){
  return 0;  
}


int main() {
    int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    size_t size_data = sizeof(data)/sizeof(data[0]);

    cout << "Testing maximum "<< endl;
    cout << "Reult: "<< maximun(data, size_data)<< endl;
    cout << endl;

    cout << "Testing oddSwap" << endl;
    cout << "a: " << data[0]<< "  b:" << data[1] << "  =  " << oddSwap(data, data+1) << endl;
    cout << endl;


    cout << "Testing expand" << endl << "Result: " << endl;
    cout << " a : [ ";
    for(int i=0; i < (size_data); i++){
        cout << data[i] << " " ;
    }
    cout << "]" << endl;
    // int expand_data [size_data*2];
    int * new_data = expand(data, size_data);
    cout << " b : [ ";
    for(int i=0; i < (size_data*2); i++){
        cout << *(new_data+i) << " " ;
    }
    cout << "]" << endl << endl;

    cout << "Testing concat" << endl;
    int concat_array[size_data + size_data];
    concat(data, size_data, data, size_data, concat_array);
    cout << "Result: [ "; 
    for(int i=0; i< (size_data + size_data); i++) cout << concat_array[i] << " ";    
    cout << "]" << endl;

    delete[] new_data; // deleting dynamically allocated arry on heap.   
    return 0;
}