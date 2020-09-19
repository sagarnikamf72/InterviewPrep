#include<bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *nxt) : val(x), nxt(next) {}
};

class Solution {
public:
    // time complexity : O(N)
    // space complexity : O(N)
    void bruteForce(ListNode* head) {
        stack<int> newValues;
        ListNode* curr = head;
        while(curr != NULL){
            newValues.push(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        while(curr != NULL){
            curr->val = newValues.top();
            newValues.pop();
            curr = curr->next;
        }
    }
    
    // time complexity : O(N)
    // space complexity : O(1)
    
    ListNode* optimized(ListNode* head){
        ListNode *prev = NULL, *curr = head, *nxt;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    ListNode* reverseList(ListNode* head) {
        return optimized(head);
        // return head;
    }
};

int main(){

	return 0;
}
