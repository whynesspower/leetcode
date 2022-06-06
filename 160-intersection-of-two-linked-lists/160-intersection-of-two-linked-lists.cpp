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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1= headA;
        while(temp1!=NULL){
            temp1->val= -1*temp1->val;
            temp1=temp1->next;
        }
        ListNode* temp2= headB;
        ListNode* ans=NULL;
        while(temp2!=NULL){
            if(temp2->val <0){
                ans=temp2;
                break;
            }
            temp2=temp2->next;
        }
        temp1=headA;
        while(temp1!=NULL){
            temp1->val= -1*temp1->val;
            temp1=temp1->next;
        }
        return ans;
    }
};