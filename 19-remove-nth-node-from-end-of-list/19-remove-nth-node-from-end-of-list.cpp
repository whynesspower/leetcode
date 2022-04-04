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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len =0;
        ListNode* temp= head;
        while(temp){
            temp=temp->next;
            len++;
        }
        if(len==1){
            return NULL;
        }
        if(len==2){
            if(n==1){
                head->next=NULL;
                return head;
            }
            else{
                return head->next;
            }
        }
        int k=0;
        temp=head;
        ListNode* first=NULL,*second;
        while(temp){
            if(k==(len-n)){
                second=temp;
                break;
            }
            k++;
            first=temp;
            temp=temp->next;
        }
        if(first==NULL){
            return head->next;
        }
        else{
            first->next= second->next;
            return head;
        }
        
        
    }
};