/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans= new ListNode(0);
        int carry=0;
        int sum;
        ListNode* finalans= ans;
        while(l1 or l2){
            sum= carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            ans->next= new ListNode(sum%10);
            ans=ans->next;
            carry=sum/10;
        }
        
        if(carry>0){
            ans->next= new ListNode(carry);
        }
        return finalans->next;
        
    }
};