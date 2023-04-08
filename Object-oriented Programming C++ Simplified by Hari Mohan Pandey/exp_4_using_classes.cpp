/*
From Book: Oobject Oriented Programming C++ Simplified.

Experiment-4 : Programs to create singly and doubly linked lists and perform insertion and deletion Operations. 
                Using self referential classes, new and delete operators.
*/


// ---- With using Classes ------
#include <iostream>

struct node{
    float data;
    node * link;
};

class doubly_linked_list{
    node* headNode;
public:
    doubly_linked_list(){
        headNode = nullptr; // initial node's address in nullptr with no data and link variables created.
                            // if we try to access the member variables of nullptr,  we ill get Segmentation Error!
    }
    void add_data_from_start(float data){
        
        node* newNode = new node;    
        newNode->data = data;
        newNode->link = headNode; // prev link
        headNode = newNode;   // updated header.
    }
    void add_data_from_end(float data){
        node* iter = headNode;

        while(iter->link != nullptr) // finding which node points to nullptr
            iter = iter->link; 

        node* newNode = new node;    // creating a new node
        newNode->data = data;
        newNode->link = nullptr; // linking new node to nullptr.
        iter->link = newNode;    // linking the previously last node to the new node.
    }

    void add_data_at(unsigned int location, float data){ // starting from zero as the first entry.
        node* iter = headNode;
        for(int i=1; i < location; i++) iter = iter->link;
        node* newNode = new node;
        newNode->data = data;
        newNode->link = iter->link;
        iter->link = newNode;
    }

    void display_List(){
        node* alink = headNode;
        while (alink != nullptr)
        {
            std::cout << "["<< alink->data << "] ";
            alink = alink->link;
        }
    }
};

int main(){
    node* list = new node{.data = 0, .link = nullptr };
    doubly_linked_list alist;
    
    for (int i = 5; i<10; i++) alist.add_data_from_start(i);
    alist.display_List();
    std::cout<< std::endl;

    for (int i = 5; i<10; i++) alist.add_data_from_end(i);
    alist.display_List();
    std::cout<< std::endl;
    
    for (int i = 0; i<5; i++) alist.add_data_at(i+5, i);
    alist.display_List();
    std::cout<< std::endl;
}