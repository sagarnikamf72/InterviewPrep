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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *h1 = l1, *h2 = l2, *currNode = head;
        int carry = 0;
        while(h1 != NULL && h2 != NULL){
            int currDigit = carry + h1->val + h2->val;
            carry = currDigit/10;
            currDigit %= 10;
            currNode->next = new ListNode(currDigit);
            currNode = currNode->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        while(h1 != NULL){
            int currDigit = carry + h1->val;
            carry = currDigit/10;
            currDigit %= 10;
            currNode->next = new ListNode(currDigit);
            currNode = currNode->next;
            h1 = h1->next;
        }
        while(h2 != NULL){
            int currDigit = carry + h2->val;
            carry = currDigit/10;
            currDigit %= 10;
            currNode->next = new ListNode(currDigit);
            currNode = currNode->next;
            h2 = h2->next;
        }
        while(carry){
            int currDigit = carry;
            carry = currDigit/10;
            currDigit %= 10;
            currNode->next = new ListNode(currDigit);
            currNode = currNode->next;
        }
        return head->next;
    }
};

int main(){
	
	return 0;
}
