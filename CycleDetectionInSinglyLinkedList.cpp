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

bool detectCycle(Node *head) {
    Node *fast = head;
    Node *slow = head;
    if(head == nullptr || head->next == nullptr)
        return false;
    if(fast->next == nullptr) return false;
    fast = fast->next->next;
    while(fast != nullptr) {
        if(slow == fast) return true;
        slow = slow->next;
        if(fast->next == nullptr) break;
        fast = fast->next->next;
    }
    return false;
}