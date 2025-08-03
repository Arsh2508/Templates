#include <iostream>
#include "DoublyLinkedList.hpp"

int main()
{
    DoublyLinkedList<int> list1;
    list1.push_back(2);
    list1.push_front(23);
    list1.push_back(5);
    list1.push_front(7);

    list1.print();

    DoublyLinkedList<int> list2;
    list2.push_back(3);
    list2.push_back(4);
    list2.push_back(5);

    list1.merge(list2);

    list1.print();


    
    return 0;
}
