#include "DoublyLinkedList.hpp"
#include <iostream>
#include <exception>

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head{nullptr}, tail{nullptr} {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) : head{nullptr}, tail{nullptr} 
{
    Node *tmp = other.head;
    while(tmp) {
        push_back(tmp->data);
        tmp = tmp->next;
    }
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList &rhs)
{
    if(this == &rhs){
        return *this;
    }
    clear();

    Node *tmp = rhs.head;
    while(tmp) {
        push_back(tmp->data);
        tmp = tmp->next;
    }

    return *this;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList &&other) noexcept : head{other.head}, tail{other.tail} 
{
    other.head = nullptr;
    other.tail = nullptr;
}

template <typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(DoublyLinkedList &&rhs) noexcept
{
    if(this == &rhs){
        return *this;
    }

    clear();
    head = rhs.head;
    tail = rhs.tail;

    rhs.head = nullptr;
    rhs.tail = nullptr;

    return *this;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& val)
{
    Node *new_node = new Node(val);
    if(!head) {
        head = new_node;
        tail = head;
    }
    else{
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    } 
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& val) 
{
    Node *node = new Node(val);
    if(head == nullptr) {
        head = node;
        tail = head;
    }
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }    
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
    Node *curr = head;

    while(curr) {
        Node *tmp = curr;
        curr = tmp->next;
        delete tmp;
    }

    head = nullptr;
    tail = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::print()
{
    Node *curr = head;
    while(curr) {
        std::cout<<curr->data<<" ";
        curr = curr->next;
    }
    std::cout<<std::endl;
}

template <typename T>
void DoublyLinkedList<T>::pop_front()
{
    if(!head) {
        return;
    }

    Node *tmp = head;
    head = head->next;

    if(head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }

    delete tmp;
}

template <typename T>
void DoublyLinkedList<T>::pop_back()
{
    if(!tail) {
        return;
    }

    Node *tmp = tail;
    tail = tail->prev;

    if(tail) {
        tail->next = nullptr;
    }
    else{
        head = nullptr;
    }

    delete tmp;
}

template <typename T>
void DoublyLinkedList<T>::erase(Node *node)
{
    if(!node) {
        return;
    }

    if(node == head) {
        pop_front();
        return;
    }

    if(node == tail) {
        pop_back();
    }

    Node *prevNode = node->prev;
    Node *nextNode = node->next;

    if(prevNode) prevNode->next = nextNode;
    if(nextNode) nextNode->prev = prevNode;

    delete node;
    
}

template <typename T>
T& DoublyLinkedList<T>::front() const
{
    if(head) throw std::runtime_error("Empty list");
    return head->data;
}

template <typename T>
T& DoublyLinkedList<T>::back() const 
{
    if(!tail) throw std::runtime_error("Empty list");
    return tail->data;
}

template <typename T>
void DoublyLinkedList<T>::merge(DoublyLinkedList& other)
{
    if(!other.head) {
        return;
    }

    if(!head) {
        head = other.head;
        tail = other.tail;
    }
    else {
        tail->next = other.head;
        other.head->prev = tail;
        tail = other.tail;
    }

    other.head = nullptr;
    other.tail = nullptr;
}
