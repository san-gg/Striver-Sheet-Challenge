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

int findIntersection(Node *firstHead, Node *secondHead) {
    unordered_set<Node*> val;
    int pos = -1;
    while(firstHead != nullptr && secondHead != nullptr) {
        if(val.find(firstHead) != val.end()) {
            pos = firstHead->data;
            break;
        }
        val.insert(firstHead);
        if(val.find(secondHead) != val.end()) {
            pos = secondHead->data;
            break;
        }
        val.insert(secondHead);
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    if(firstHead) {
        while(firstHead != nullptr) {
            if(val.find(firstHead) != val.end()) {
                pos = firstHead->data;
                break;
            }
            firstHead = firstHead->next;
        }
    }
    if(secondHead) {
        while(secondHead != nullptr) {
            if(val.find(secondHead) != val.end()) {
                pos = secondHead->data;
                break;
            }
            secondHead = secondHead->next;
        }
    }
    return pos;
}