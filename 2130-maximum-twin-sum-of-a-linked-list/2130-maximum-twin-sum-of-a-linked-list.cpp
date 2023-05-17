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
    // returns head of the reversed linked list
    ListNode* reverseList(ListNode* curr){
     if(!curr or curr->next==nullptr) return curr;
        ListNode* t= curr->next;
        ListNode* p=reverseList(t);
        curr->next->next=curr;
        curr->next=nullptr;
        return p; 
    }
    
    
    int pairSum(ListNode* head) {
        // find the middle node
        // reverse list from the node after the middle node
        // head 1 and head 2 
        // find max sum of highest head
            int res = 0;
            auto slow = head, fast = head;
            while (fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
            }
            slow = reverseList(slow);
            while (slow != nullptr) {
                res = max(res, slow->val + head->val);
                slow = slow->next;
                head = head->next;
            }
            return res;
    }
};