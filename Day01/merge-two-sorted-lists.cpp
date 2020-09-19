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
    //time complexity : O(N*M)
    //auxilary space complexity : O(1)
    // bruteForce1
    // compare elements at pos l1, l2
    // if element at l1 <= element at l2 continue
    // else swap values of l1 and l2 and insert new element at l2 at its correct position in second list
    
    
    
    // time complexity : O(N+M)
    // auxilary space complexity : O(N + M) for vector of size N + M 
    void bruteForce2(ListNode* h1, ListNode* h2){
        ListNode *tmp1 = h1, *tmp2 = h2;
        vector<int> nums;
        while(tmp1 != NULL && tmp2 != NULL){
            if(tmp1->val > tmp2->val){
                nums.push_back(tmp2->val);
                tmp2 = tmp2->next;
            }
            else{
                nums.push_back(tmp1->val);
                tmp1 = tmp1->next;
            }
        }
        while(tmp1 != NULL){
            nums.push_back(tmp1->val);
            tmp1 = tmp1->next;
        }
        while(tmp2 != NULL){
            nums.push_back(tmp2->val);
            tmp2 = tmp2->next;
        }
        
        tmp1 = h1;
        bool flag = true;
        for(int curr = 0; curr < (int)nums.size(); curr++){
            tmp1->val = nums[curr];
            if(tmp1->next == NULL && flag){
                tmp1->next = h2;
                flag = false;
            }
            tmp1 = tmp1->next;
        }
    }
    
        // Time complexity : O(N)
    // Auxilary Space complexity : O(N) {Stack memory needed for recursive calls}
    ListNode* solve(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val <= l2->val){
            l1->next = solve(l1->next, l2);
            return l1;
        }
        else{
            l2->next = solve(l1, l2->next);
            return l2;
        }
    }
    // Time complexity : O(N)
    // Auxilary Space complexity : O(1)
    ListNode* solve2(ListNode* l1, ListNode* l2){
        ListNode* dummyHead = new ListNode(0, l1);
        ListNode* curr = dummyHead;
        while(curr != NULL && curr->next != NULL && l2 != NULL){
            if(curr->next->val > l2->val){
                ListNode* temp = l2->next, *temp2 = curr->next;
                curr->next = l2;
                l2 = temp;
                curr->next->next = temp2;
                curr = curr->next;
            }
            else{
                curr = curr->next;
            }
        }
        if(curr->next == NULL) curr->next = l2;
        
        return dummyHead->next;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        solve2(l1, l2);
        return l1;
    }
};

int main(){
	
	return 0;
}
