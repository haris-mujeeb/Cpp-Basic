#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template <typename Type>
struct Node {
    Type data;
    Node *next;
    Node *prev;
};

template <class T>
class linkedList {
    public:
        Node<T>* m_head;
        Node<T>* m_tail;
        // linkedList(){};
        unsigned int length = 0;
        linkedList(T newData);
        ~linkedList();
        void append_back(T newData);
        void push_front(T newData);
        int pop_back();
        int pull_front();
        T getHeadData();
        T getTailData();
};

// Template need to 

template<class T>
linkedList<T>::linkedList(T newData){
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    m_tail = newNode;
    m_head = newNode;
    length = 1;
}

template <class T>
linkedList<T>::~linkedList(){
    while(length!=0){pop_back();} 
}


template<class T>
void linkedList<T>::append_back(T newData){    // add to the tail of the list
    Node<T>* newNode = new Node<T>;    // allocated in heap
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = m_tail;
    m_tail->next = newNode;
    m_tail = newNode;
    length++;
}

template<class T>
void linkedList<T>::push_front(T newData){  // add to the head of the list.
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = m_head;
    newNode->prev = nullptr;
    m_head->prev = newNode;
    m_head = newNode;
    length++;
}

template<class T>
int linkedList<T>::pop_back(){    // remove from the tail of the list.
    if (length > 1) {
        m_tail = m_tail->prev;
        delete m_tail->next;  //! Segmentation Error 
        m_tail->next = nullptr;
        length--;
        return 0;
    }
    else {
        delete m_tail;
        m_tail = nullptr;
        m_head = nullptr;
        length--;
        return 0;
    };
}

template<class T>
int linkedList<T>::pull_front(){   // remove from the head of the list.
    if (length > 1) {
        m_head = m_head->next;
        delete m_head->prev;
        m_head->prev = nullptr;
        length--;
        return 0;
    }
    else {
        delete m_head;
        m_tail = nullptr;
        m_head = nullptr;
        length--;
        return 0;
    };
    return -1;
}

template<class T>
T linkedList<T>::getHeadData() { 
        return m_head->data;
}

template<class T>
T linkedList<T>::getTailData() { 
        return m_tail->data;
}

#endif  // LINKED_LIST_HPP