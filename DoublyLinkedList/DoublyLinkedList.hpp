#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

template <typename T>
class DoublyLinkedList {
    public:
    struct Node {
        T data;
        Node *next;
        Node *prev;
        Node(const T& val) : data{val}, next{nullptr}, prev{nullptr} {}
    };
    
    DoublyLinkedList();
    
    DoublyLinkedList(const DoublyLinkedList &other);
    DoublyLinkedList& operator=(const DoublyLinkedList &rhs);
    
    DoublyLinkedList(DoublyLinkedList &&other) noexcept;
    DoublyLinkedList& operator=(DoublyLinkedList &&rhs) noexcept;

    void push_front(const T& val);
    void push_back(const T& val);

    void pop_front();
    void pop_back();
    void erase(Node *node);
    void clear();

    T& front() const;
    T& back() const;

    Node *find(const T& value) const
    {
        Node *curr = head;
        while(curr) {
            if(curr->data == value){
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    void merge(DoublyLinkedList& other);

    void print();
        
    ~DoublyLinkedList();
    
    
    private:
    Node *head;
    Node *tail;
}; 

#include "DoublyLinkedList.cpp"

#endif