#include<bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    // Time Complexity O(N)
    // Space Complexity O(N)
    
    Node* util(Node* head){
        Node* curr = head, *prev = NULL, *nxt;
        while(curr != NULL){
            nxt = curr->next;
            if(curr->child != NULL){
                Node* tmp = curr;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr = util(curr->child);
                curr->next = nxt;
                if(nxt != NULL)
                nxt->prev = curr;
                tmp->child = NULL;
            }
            prev = curr;
            curr = nxt;
        }
        return prev; 
    }
    Node* flatten(Node* head) {
        Node* curr = head, *nxt;
        while(curr != NULL){
            nxt = curr->next;
            if(curr->child != NULL){
                Node* tmp = curr;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr = util(curr->child);
                curr->next = nxt;
                if(nxt != NULL)
                nxt->prev = curr;
                tmp->child = NULL;
            }
            curr = nxt;
        }
        return head; 
    }
};

int main(){
	return 0;
}
