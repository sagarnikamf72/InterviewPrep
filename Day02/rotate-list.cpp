class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head;
        int cnt = 0;
        while(slow != NULL){
            ++cnt;
            slow = slow->next;
        }
        slow = head;
        k = k%cnt;
        for(int i = 0; i < k; i++){
            fast = fast->next;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};
