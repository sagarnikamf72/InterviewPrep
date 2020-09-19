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
    // Approach 1:
    // * Find the total number of elements in the linked list by traversing the list, let it be cnt
    // * Then n-th node from the end is (cnt - n + 1)th node from the begining
    // * remove (cnt - n + 1)th node from the begining
    
    // We need to traverse the list twice
    // Time complexity : O(N)
    // Space complexity : O(1)
    ListNode* Approach1(ListNode* head, int n) {
        ListNode* curr = head;
        int cnt = 0;
        while(curr != NULL){
            cnt++;
            curr = curr->next;
        }
        if(cnt == n){
            head = head->next;
            return head;
        }
        
        cnt -= (n);
        
        curr = head;
        // move to node before the node to be deleted
        for(int i = 1; i < cnt; i++){
            curr = curr->next;
        }
        if(curr->next != NULL)curr->next = curr->next->next;
        
        return head;
    }
    
    // Approach 2:
    // * I can consider two pointers, lets say first and second
    // * Initially second pointer will point to the n+1th node and first node will point to 0th node(dummy node)
    // * We will move both pointers by one untill the second pointer reaches a NULL value
    // * So after above traversal the first pointer will point at node the comes before the node to be deleted
    
    // We traverse the list only once
    // Time complexity : O(N)
    // Space complexity : O(1)
    
    ListNode* Approach2(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *first = dummyHead, *second = dummyHead;
        
        // move second pointer to (n+1)th node
        for(int i = 0; i <= n; i++){
            second = second->next;
        }
        
        while(second != NULL){
            second = second->next;
            first = first->next;
        }
        
        first->next = first->next->next;
        
        return dummyHead->next;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return Approach2(head, n);
    }
};



int main(){
	
	return 0;
}
