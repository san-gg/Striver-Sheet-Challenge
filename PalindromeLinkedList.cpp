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

bool isPalindrome(LinkedListNode<int> *head) {
    LinkedListNode<int>* mid = head;
    LinkedListNode<int>* start = head;
    LinkedListNode<int>* end = head;
    int num = 2;
    if(head == nullptr || head->next == nullptr)
        return true;
    head = head->next;
    while(head != nullptr) {
        if(num % 2) mid = mid->next;
        end = head;
        head = head->next;
        ++num;
    }
    LinkedListNode<int>* rev1 = mid->next;
    LinkedListNode<int>* rev2 = rev1->next;
    head = (rev2 == nullptr)? nullptr : rev2->next;
    rev1->next = mid;
    while(head != nullptr) {
        rev2->next = rev1;
        rev1 = rev2;
        rev2 = head;
        head = head->next;
    }
    if(rev2 != nullptr) rev2->next = rev1;
    while(start != mid) {
        if(start->data != end->data) return false;
        start = start->next;
        end = end->next;
    }
    if(start->data != end->data) return false;
    return true;
}