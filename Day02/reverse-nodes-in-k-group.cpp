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
    ListNode* reverse(ListNode* head, int k){
        int cnt = 0;
        ListNode* prev = NULL, *curr = head, *nxt;
        while(curr != NULL && cnt < k){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head, *dummy = NULL, *nxt;
        ListNode* tail = head, *start = NULL, *prevTail = NULL;
        int cnt = 0;
        while(curr != NULL){
            ++cnt;
            nxt = curr->next;
            if(cnt%k == 0){
                start = curr;
                reverse(tail, k);
                if(prevTail != NULL){
                    prevTail->next = start;
                }
                else{
                    dummy = start;
                }
                prevTail = tail;
                tail->next = NULL;
                tail = nxt;
            }
            curr = nxt;
        }
        cout << cnt << endl;
        if(cnt%k != 0){
            cout << tail->val << endl;
            if(prevTail != NULL){
                prevTail->next = tail;                
            }
            else{
                dummy = head;
            }

        }
        return dummy;
    }
};

int main(){
	return 0;
}
