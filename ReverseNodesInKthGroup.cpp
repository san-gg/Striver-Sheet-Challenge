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

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    vector<Node*> ptr;
    Node *st = head;
    while(st != nullptr) {
        ptr.push_back(st);
        st = st->next;
    }
    int sz = ptr.size();
    int x = 0;
    int y = 0;
    for(int i = 0; i < n; i++) {
        y = min(y + b[i], sz);
        int p1 = x;
        int p2 = y - 1;
        while(p1 < p2) {
            swap(ptr[p1]->data, ptr[p2]->data);
            ++p1;
            --p2;
        }
        x = y;
    }
    return head;
}