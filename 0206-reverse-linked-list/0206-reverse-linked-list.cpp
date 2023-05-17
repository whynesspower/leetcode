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
    ListNode* reverseList(ListNode* curr) {
     if(!curr or curr->next==nullptr) return curr;
        ListNode* t= curr->next;
        ListNode* p=reverseList(t);
        curr->next->next=curr;
        curr->next=nullptr;
        return p; 
    }
};