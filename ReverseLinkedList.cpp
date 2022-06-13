#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == nullptr) return head;
    LinkedListNode<int> *p1 = head;
    LinkedListNode<int> *p2 = head->next;
    LinkedListNode<int> *tmp = nullptr;
    if(p2 == nullptr) return head;
    p1->next = nullptr;
    while(p2 != nullptr) {
        tmp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = tmp;
    }
    return p1;
}