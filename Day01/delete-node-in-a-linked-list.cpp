#include<bits/stdc++.h>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
};

class Solution {
public:
    // time complexity : O(N)
    // space complexity : O(1)
    void bruteForce(ListNode* node) {
        ListNode* curr = node;
        while(curr != NULL){
            curr->val = curr->next->val;
            if(curr->next->next == NULL) curr->next = NULL;
            curr = curr->next;
        }
    }
    
    // time complexity : O(1)
    // space complexity : O(1)
    // Approach: {
            // For deleting nth node we need access to (n-1)th node
            // Swap the value of node to  be deleted with the value of next node
            // delete the next node
    // }
    void optimized(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
    
    void deleteNode(ListNode* node) {
        optimized(node);
    }
};