/*
From Book: Oobject Oriented Programming C++ Simplified.

Experiment-4 : Programs to create singly and doubly linked lists and perform insertion and deletion Operations. 
                Using self referential classes, new and delete operators.
*/


// ---- Without using Classes ------
#include <iostream>

struct node{
    float data;
    node * link;
};


void add_data(node* list, float data){
    node* newNode = new node;    
    newNode->data = data;
    newNode->link = list->link; // prev link
    list->link = newNode;   // updated header.
}

void display_List(node* list){
    node* alink = list->link;
    while (alink != nullptr)
    {
        std::cout << "["<< alink->data << "] ";
        alink = alink->link;
    }
}

int main(){
    node* list = new node{.data = 0, .link = nullptr };
    for (int i = 5; i<10; i++) add_data(list, i);
    display_List(list);
}
