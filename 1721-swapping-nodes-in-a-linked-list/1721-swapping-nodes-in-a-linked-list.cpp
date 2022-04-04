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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first, *second;
        int n=0;
        ListNode* temp= head;
        while(temp){
            
            temp=temp->next;
            n++;
        }
        temp=head;
        int p=1;
        while(temp!=NULL){
            if(p==k){
                first=temp;
            }
            if(p==(n-k+1)){
                second=temp;
            }
            p++;
            temp=temp->next;
        }
        int a = second->val;
        second->val= first->val;
        first->val=a;
        return head;
    }
};