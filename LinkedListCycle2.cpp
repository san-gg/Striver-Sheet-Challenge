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

Node *firstNode(Node *head)
{
	Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    if(fast != nullptr && fast->next != nullptr) {
        while(head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
    return nullptr;
}