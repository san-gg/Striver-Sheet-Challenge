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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K) {
    LinkedListNode<int>* slow = new LinkedListNode<int>(0);
    slow->next = head;
    LinkedListNode<int>* fast = head;
    if(K == 0) return head;
    while(K--) {
        fast = fast->next;
    }
    if(fast == nullptr) return head->next;
     while(fast != nullptr) {
         fast = fast->next;
         slow = slow->next;
     }
    if(slow->next->next == nullptr) {
        slow->next = nullptr;
    }
    else {
        slow->next = slow->next->next;
    }
    return head;
}