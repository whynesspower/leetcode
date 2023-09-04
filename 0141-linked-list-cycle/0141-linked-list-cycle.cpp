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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        // if(!head->next )
        ListNode*slow=head;
        ListNode*fast=head->next;
        do{
            if(fast==nullptr or fast->next==nullptr){
                return false;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        while(slow!=fast);
        return true;
    }
};