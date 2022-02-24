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
    ListNode* sortList(ListNode* head) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> q;
        ListNode* temp=head;
        while(temp!=nullptr){
            q.push({temp->val, temp});
            temp=temp->next;
        }
        
        ListNode*head1=new ListNode();
        ListNode*curr=head1;
        while(!q.empty()){
            curr->next=q.top().second;
            q.pop();
            curr=curr->next;
        }
        curr->next=nullptr;
        head1=head1->next;
        return head1;
        
        
    }
};