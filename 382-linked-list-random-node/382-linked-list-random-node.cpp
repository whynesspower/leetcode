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
    ListNode *Root;
    public:
    Solution(ListNode* Head) {
        Root=Head;
    }
    
    int getRandom() {
        int length=0;
        ListNode *Temp=Root;

        while(Temp!=nullptr){
            length++;
            Temp=Temp->next;
        }
        
        Temp=Root;
        int randomSize= rand()%length;
        
        while(randomSize){
            Temp=Temp->next;
            randomSize--;            
        }
        return Temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */