#ifndef SLLIST_HPP
#define SLLIST_HPP

template <typename T>
class SLList {
public:
    // No-arg constructor
    SLList();

    // The copy constructor
    SLList(const SLList<T>& other);
    // Assignment operator 
    SLList<T>& operator=(const SLList<T>& other);

    // The destructor
    ~SLList();

    unsigned    size() const;  // Returns the size of the list
    bool        empty() const; // Returns true if list is empty
    void        push_front(const T& val); // Insert the new node at the beginning
    void        print() const; // Print the list
    void        push_back(const T& val); // Insert the new node at the end

    T           pop_front(); // Remove the first element (node)
    void        pop_back(); // Remove the last element (node)
    void        clear();  // Clear the list
    void        rotate_right(unsigned k); // Rotates the list to the right k times


private:
    template <typename U>
    class SLLNode {
    public:
        SLLNode(const U& d = U(), SLLNode<U>* n = nullptr) 
            : data(d), next(n) { }
        
        U data;
        SLLNode<U>* next; 
    };

    SLLNode<T>* head; // The pointer to the first node
    SLLNode<T>* tail; // The pointer to the last node
    unsigned list_size;
};

#include "SLList.tpp"

#endif
