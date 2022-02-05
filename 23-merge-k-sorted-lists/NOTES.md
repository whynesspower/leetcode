priority_queue attempt
```
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
ListNode* mergeKLists(vector<ListNode*>& lists) {
priority_queue<int>pq;
for(int i=0;i<lists.size();i++){
ListNode *head= lists[i][0];
while(head!=NULL){
pq.insert(head->val);
head=head->next;
}
}
ListNode*ans;
if(!pq.empty()){
ans->val=pq.top();
pq.pop();
}
while(!pq.empty()){
ListNode* temp;
temp->val=pq.top();
pq.pop();
}
}
};
```