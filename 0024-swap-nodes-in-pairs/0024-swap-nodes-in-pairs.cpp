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
        ListNode* curr=head;
        // if(curr==nullptr) return curr;
        if(curr==nullptr or curr->next==nullptr ) return curr;
        ListNode* sec= curr->next;
        if(sec->next==nullptr){
            ListNode* t= sec->next;
            sec->next=curr;
            curr->next=t;
            return sec;
        }
        ListNode* t= swapPairs(sec->next);
        sec->next=curr;
        curr->next=t;
        return sec;
    }
};