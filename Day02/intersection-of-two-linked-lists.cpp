#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* Approach1(ListNode *headA, ListNode *headB){
		map<ListNode*, int> nodes;
        ListNode* curr = headA, *ans = NULL;
        while(curr != NULL){
            nodes.insert({curr, curr->val});
            curr = curr->next;
        }
        
        curr = headB;
        while(curr != NULL){
            if(nodes.find(curr) != nodes.end()){
                ans = curr;
                break;
            }
            curr = curr->next;
        }
        return ans;
	}
	
	ListNode* Approach2(ListNode *headA, ListNode *headB){
		ListNode* first = headA, *second = headB;
        int cntA = 0, cntB = 0;
        while(first != NULL){
            ++cntA;
            first = first->next;
        }
        while(second != NULL){
            ++cntB;
            second = second->next;
        }
        
        first = headA;
        second = headB;
        if(cntA > cntB){
            int moves = cntA - cntB;
            first = headA;
            for(int i = 0; i < moves; i++){
                first = first->next;
            }
        }
        else{
            int moves = cntB - cntA;
            second = headB;
            for(int i = 0; i < moves; i++){
                second = second->next;
            }
        }
        ListNode* ans = NULL;
        while(first != NULL && second != NULL){
            cout << first->val << " " << second->val << endl;
            if(first == second){
                ans = first;
                break;
            }
            first = first->next;
            second = second->next;
        }
        return ans;
	}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return Approach2(headA, headB);
    }
};

int main(){
	return 0;
}
