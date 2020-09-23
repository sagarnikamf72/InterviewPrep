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
    // Time Complexity O(N)
    // Space Complexity O(N)
    bool solve1(ListNode* head){
        ListNode* curr = head;
        stack<int> st;
        while(curr != NULL){
            st.push(curr->val);
            curr = curr->next;
        }
        bool flag = true;
        curr = head;
        while(curr != NULL){
            if(curr->val != st.top()){
                flag = false;
                break;
            }
            st.pop();
            curr = curr->next;
        }
        return flag;
    }
    
    // Time Complexity O(N)
    // Space Complexity O(1)
    
    bool solve(ListNode* head){
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* slow = dummyHead, *fast = dummyHead;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = NULL;
        if(fast == NULL) { // odd length list
            mid = slow;
            slow = slow->next;
            mid->next = NULL;
        }
        else{// even length list
            ListNode* tmp = slow->next;
            slow->next = NULL;
            slow = tmp;
        }
        ListNode* first = head, *second = reverse(slow);
        fast = second;
        
        while(first != mid && second != NULL) {
            if(second->val != first->val) return false;
            first = first->next;
            second = second->next;
        }
        
        fast = reverse(fast);
        ListNode* curr = head;
        while(curr != NULL && curr->next != NULL){
            curr = curr->next;
        }
        if(curr != NULL) curr->next = fast;
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        return solve(head);
    }
    
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* curr = head, *prev = NULL, *nxt;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
 
};


int main(){
	return 0;
}
