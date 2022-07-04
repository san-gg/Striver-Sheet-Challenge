#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int>* tmp = head;
    if(head == nullptr) return nullptr;
    while(tmp != nullptr) {
        LinkedListNode<int>* n = new LinkedListNode<int>(tmp->data);
        n->random = nullptr;
        n->next = tmp->next;
        tmp->next = n;
        tmp = tmp->next->next;
    }
    tmp = head;
    while(tmp != nullptr) {
        if(tmp->random != nullptr)
            tmp->next->random = tmp->random->next;
        tmp = tmp->next->next;
    }
    tmp = head->next;
    while(tmp != nullptr && tmp->next != nullptr) {
        tmp->next = tmp->next->next;
        tmp = tmp->next;
    }
    LinkedListNode<int>* ans = head->next;
    tmp = head;
    while(tmp != nullptr && tmp->next != nullptr) {
        tmp->next = tmp->next->next;
        tmp = tmp->next;
    }
    return ans;
}
