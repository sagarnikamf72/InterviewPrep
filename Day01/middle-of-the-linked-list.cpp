#include<bits/stdc++.h>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // traversing linked list twice
    ListNode* bruteForce(ListNode* head){
        int cnt = 0;
        ListNode* curr = head;
        while(curr != NULL){
            ++cnt;
            curr = curr->next;
        }
        cnt = cnt/2;
        curr = head;
        for(int i = 0; i < cnt; i++){
            curr = curr->next;
        }
        return curr;
    }
    // traversing linked list once 
    ListNode* optimized(ListNode* head){
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* middleNode(ListNode* head) {
        return optimized(head);
    }
};

int main(){
	
	return 0;
}
