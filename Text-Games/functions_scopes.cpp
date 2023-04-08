#include <iostream>
using namespace std;

void func();

int main(){
    int var= 5;
    cout << "1. "<< var << endl;
    func();
    cout << "3. "<< var << endl;

    {
        cout << "4. " << var << endl;

        int var = 10;
        cout << "5. " << var << endl;
    }
        cout << "6. " << var << endl;
        return 0;
}

void func(){
    int var = -5;
    cout << "2. "<< var<<endl;
}