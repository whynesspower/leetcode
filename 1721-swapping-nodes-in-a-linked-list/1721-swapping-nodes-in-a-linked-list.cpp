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
        vector<ListNode*>v;
        ListNode* curr=head;
        while(curr!=nullptr){
            v.push_back(curr);
            curr=curr->next;
        }
        ListNode* a= v[k-1];
        int n=v.size();
        ListNode* b= v[n-k];
        int temp= a->val;
        a->val=b->val;
        b->val=temp;
        return v[0];
    }
};