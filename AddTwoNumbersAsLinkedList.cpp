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

Node *addTwoNumbers(Node *head1, Node *head2) {
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;
    Node *t1 = head1;
    Node *t2 = head2;
    Node *t3 = nullptr;
    
    while(t2 != nullptr) {
        int nos = (t2->data + t1->data) / 10;
        t1->data = (t1->data + t2->data) % 10;
        t2 = t2->next;
        if(t1->next == nullptr) {
            t3 = t1;
            t1->next = new Node(0);
        }
        t1 = t1->next;
        t1->data += nos;
    }
    while(t1->data / 10) {
        int nos = t1->data / 10;
        t1->data = t1->data % 10;
        if(t1->next == nullptr) {
            t3 = t1;
            t1->next = new Node(0);
        }
        t1 = t1->next;
        t1->data += nos;
    }
    if(t3 != nullptr && t1->data == 0) {
        t3->next = 0;
    }
    return head1;
}