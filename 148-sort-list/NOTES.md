O(N) space and O(nlogn) time
​
``class Solution {
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
​
O(1) space and O(nlogn) time
Merge Sort
​
​
​
​
​
​
​