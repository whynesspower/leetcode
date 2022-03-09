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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        map<int,int> mp;
        ListNode* temp=head;
        
        while(temp!=NULL){
            mp[temp->val]++;
            temp=temp->next;
        }
        
        ListNode* ans= new ListNode(0);
        ListNode* finalans=ans;
        for(auto it:mp){
            if(it.second>1) continue;
            else{
                ListNode* temp2 = new ListNode(it.first);
                ans->next=temp2;
                ans=temp2;
            }
        }
        return finalans->next;
    }
};