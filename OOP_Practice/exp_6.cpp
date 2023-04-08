/*

From Book: Oobject Oriented Programming C++ Simplified.

Experiment-6 : Programs illustrating the various forms of inheritance :
                1. Single Inheritance.
                2. Multiple Inheritances.
                3. Multilevel Inheritance.
                4. Hierarchical inheritance, etc.

*/
#include <iostream>

class super{
    int sup_a;
protected:
    void sup_input(int a){sup_a = a;}
    int sup_show() const {return sup_a;};

};

class sub : protected super{
    int sub_a;
protected:
    void sub_input(int a){
        sup_input(a);
        sub_a = 2*sup_show();
        }
    int sub_show()const {return sub_a;};
};

class sub_sub : protected sub{
        int sub_sub_a;
public:
    void sub_sub_input(int a){
        sub_input(a);
        sub_sub_a = sup_show()+sub_show();
        }
    int sub_sub_show()const {return sub_sub_a;};
};

int main(){
    int i = 195;
    sub_sub s;
    s.sub_sub_input(i); 
    std::cout << s.sub_sub_show();

}