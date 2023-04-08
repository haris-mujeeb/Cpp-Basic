/*
From Book: Oobject Oriented Programming C++ Simplified.

Experiment-4 : Programs to create singly and doubly linked lists and perform insertion and deletion Operations. 
                Using self referential classes, new and delete operators.
*/


// ---- With using Classes ------
#include <iostream>

struct node{
    node * front;
    float data;
    node * back; 
};

class doubly_linked_list{
    node* headNode;

public:
    doubly_linked_list(float data){
        headNode = new node;
        headNode->back = headNode->front = nullptr;
        headNode->data = data;
    }

    void add_data_from_start(float data){
        node* newNode = new node;    
        newNode->data = data;
        newNode->front = headNode->front;
        newNode->back = headNode; 
        headNode->front = newNode; // newNode is now if front of previously HeadNote.
        headNode = newNode; // renaming the newNode as the headNode.
    }

    void add_data_from_end(float data){
        node* newNode = new node;    
        newNode->data = data;
        node* iter = headNode;
        while(iter->back != nullptr) iter = iter->back; // finding the end.
        newNode->back = iter->back;
        newNode->front = iter; 
        iter->back = newNode; // newNode is now if front of previously HeadNote.
    }

    void add_data_at(unsigned int location, float data){ // starting from zero as the first entry.
        node* iter = headNode;
        for(int i=1; i < location; i++) iter = iter->back;
        node* newNode = new node;
        newNode->data = data;
        newNode->back = iter->back;
        iter->back = newNode;
    }

    void display_List_from_Start(){
        node* alink = headNode;
        while (alink != nullptr)
        {
            std::cout << "["<< alink->data << "] ";
            alink = alink->back;
        }
    }
};

int main(){

    doubly_linked_list alist(4);
    
    for (int i = 5; i<10; i++) alist.add_data_from_start(i);
    alist.display_List_from_Start();
    std::cout<< std::endl;

    for (int i = 5; i<10; i++) alist.add_data_from_end(i);
    alist.display_List_from_Start();
    std::cout<< std::endl;
    
    for (int i = 0; i<4; i++) alist.add_data_at(i+5, i);
    alist.display_List_from_Start();
    std::cout<< std::endl;
}