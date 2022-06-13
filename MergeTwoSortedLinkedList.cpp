#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    Node<int> *head, *tmp;
    if(first == nullptr) return second;
    if(second == nullptr) return first;
    if(first->data < second->data) {
        head = first;
        tmp = first;
        first = first->next;
    }
    else {
        head = second;
        tmp = second;
        second = second->next;
    }
    while(first != nullptr && second != nullptr) {
        if(first->data < second->data) {
            tmp->next = first;
            first = first->next;
            tmp = tmp->next;
        }
        else {
            tmp->next = second;
            second = second->next;
            tmp = tmp->next;
        }
    }
    if(first != nullptr) {
        tmp->next = first;
    } else {
        tmp->next = second;
    }
    
    return head;
}