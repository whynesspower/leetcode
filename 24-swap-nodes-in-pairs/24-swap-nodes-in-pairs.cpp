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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        vector<ListNode*> temp;
        ListNode* curr= head;
        
        while(curr!=NULL){
            temp.push_back(curr);   
            curr=curr->next;
        }
        
        for(int i=0;i<temp.size();i=i+2){
            if(i!=temp.size()-1) swap(temp[i], temp[i+1]);
            
        }
        
        ListNode* curr2=temp[0];
        ListNode* ans= curr2;
        
        for(int i=1;i<temp.size();i++){ 
            
            if(i!=temp.size()-1){
                curr2->next=temp[i];
                curr2=curr2->next;
                
            }
            if(i==temp.size()-1){
                curr2->next=temp[i];
                curr2->next->next=NULL;
                break;
            }
        }
        
        return ans;
    }
};