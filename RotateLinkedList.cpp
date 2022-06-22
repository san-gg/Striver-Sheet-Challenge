#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) {
    Node* st = head;
    Node* n1 = nullptr;
    stack<Node*> n;
    int c = 0;
    while(head != nullptr) {
        n.push(head);
        c += 1;
        head = head->next;
    }
    k = k % c;
    while(k--) {
        n1 = n.top();
        n1->next = st;
        st = n1;
        n.pop();
    }
    (n.top())->next = nullptr;
    return st;
}