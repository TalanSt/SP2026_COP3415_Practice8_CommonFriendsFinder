#include "SLList.hpp"
#include <iostream>
#include <stdexcept>

template <typename T>
SLList<T>::SLList() {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

template <typename T>
SLList<T>::~SLList() {
    clear();
}

template <typename T>
unsigned SLList<T>::size() const {
    return list_size;
}

template <typename T>
bool SLList<T>::empty() const {
    return (size() == 0);
}

template <typename T>
void SLList<T>::push_front(const T& val) {
    // Add new node at the beginning
    //SLLNode* new_node = new SLLNode(val);
    //new_node->next = head;
    //head = new_node;

    // Alternative way
    head = new SLLNode<T>(val, head);

    // Increase the list size
    list_size++;

    if (size() == 1) {
        tail = head;
    }
}

template <typename T>
void SLList<T>::print() const {
    std::cout << "{ ";

    SLLNode<T>* cur = head;
    while (cur) {
        std::cout << cur->data;
        if (cur->next) {
            std::cout << " -> ";
        }
        cur = cur->next; // Goes to the next node
    }
    std::cout << " }\n";
}

template <typename T>
void SLList<T>::push_back(const T& val) {
    if (empty()) {
        push_front(val);
        return;
    }
    tail->next = new SLLNode<T>(val); // Add the node to the end
    tail = tail->next; // Move the tail

    list_size++;
}

template <typename T>
T SLList<T>::pop_front() {
    T res;
    if (!empty()) {
        res = head->data;
        SLLNode<T>* old_head = head;
        head = head->next;

        delete old_head; // Free the memory

        list_size--;
        if (empty()) {
            tail = head;
        }
    }
    else {
        throw std::logic_error("pop_front: empty list");
    }

    return res;
}

template <typename T>
void SLList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void SLList<T>::pop_back() {
    if (empty() || size() == 1) {
        pop_front();
    }
    else {
        SLLNode<T>* old_tail = tail;
        SLLNode<T>* cur = head;
        //search second from the last node
        while(cur->next != tail) {
            cur = cur->next;
        }
        tail = cur;
        tail->next = nullptr;
        delete old_tail;
        list_size--;
    }
}

template <typename T>
SLList<T>::SLList(const SLList<T>& other) {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
    SLLNode<T>* cur = other.head;
    while (cur) {
        push_back(cur->data);
        cur = cur->next;
    }
}

template <typename T>
SLList<T>& SLList<T>::operator=(const SLList<T>& other) {
    clear();
    SLLNode<T>* cur = other.head;
    while (cur) {
        push_back(cur->data);
        cur = cur->next;
    }
    
    return *this;
}

template <typename T>
void SLList<T>::rotate_right(unsigned k) {
    if(empty() || size() == 1) return;

    for(int i = 0; i < k; i++) {
        SLLNode<T>* cur_2nd_last = head;
        for(int j = 0; j < size() - 2; j++) {
            cur_2nd_last = cur_2nd_last->next;
        }

        
        tail->next = head;
        head = tail;
        tail = cur_2nd_last;
        cur_2nd_last->next = nullptr;
    }
}
