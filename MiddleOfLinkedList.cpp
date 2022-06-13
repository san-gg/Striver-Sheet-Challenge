#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/

Node *findMiddle(Node *head) {
    Node *mid = head;
    if(head == nullptr) return nullptr;
    int no = 1;
    while(head != nullptr) {
        if(no % 2 == 0)
            mid = mid->next;
        ++no;
        head = head->next;
    }
    return mid;
}