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

    ListNode* merge(ListNode* one, ListNode* two){
        if(!one and !two ) return nullptr;
        if(!one) return two;
        if(!two) return one;
        if(one->val < two->val){
            one->next=merge(one->next, two);
            return one;
        }
        else{
            two->next=merge(one, two->next);
            return two;
        }
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* slow=head, *fast=head->next;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* second=slow->next;
        slow->next=nullptr;
        
        ListNode* left=sortList(head);
        ListNode* right=sortList(second);
        return merge(left, right);
        
    }
};