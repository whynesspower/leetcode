/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL or head->next==NULL) return NULL;
        ListNode *slow=head, *fast=head;
        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) break;
        }
        if(!(fast and fast->next)) return NULL;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
        
        
    }
};