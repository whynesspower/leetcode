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


// ====================================
// method 2 - reservoir sampling


Reframing the question:-

Return a random node from linked list. Each node should have same probability to get chosen .

NOTE: I think this question has some missing information .Let's discuss them at the end of post for better understanding. Don't skip the middle part ;)

Intuition :-

One way to solve this question can be that, we first traverse the entire linkedlist and thus we get to know the length of linkedlist .After ths we just call a random node with the help of rand( )%length .
The second way is not something that comes with intuition it's something that needs to be informed and this method is the famous reservoir sampling method .
The Reservoir sampling method:-

It's not a tough algo it's just that we usually don't know this . So before starting let's discuss a bit about probability .

When we read the first node head, if the stream ListNode stops here, we can just return the head->val. The probability of picking here is 1/1 .
When we goto second node we can decide if we replace the result r or not. The possibility is 1/2. So now we need to genereate a random number between 0 & 1 and if it is equals to 1 replace r with the current node else we don't traumantize r, so it's value is till the value of head .
Now let's goto third node and we can decide if we can replace the result r or not . The probability of picking the third node will be 1/3 . and not picking up will be 2/3 . So now we generate a random number between 0-to-2 if the result is 2 then we replace r with the value of indexed node 2
We need to continue this till the end of list node .
To conclude, if we have n different balls than the equal probability of picking any one of them will be 1/n .
Now that's it, this is what reservoir sampling method looks like, told you its easy ;)
Code:-

class Solution {
public:
    //Note : head is guaranteed to be not null, so it contains at least one node.
    ListNode* HeadNode;
    Solution(ListNode* head) {
       HeadNode = head;
    }
    //returns value of a random node
    int getRandom() {
        int res, len = 1;
        ListNode* x = HeadNode;
        while(x){
            if(rand() % len == 0){
                res = x->val;
            }
            len++;
            x = x->next;
        }
        return res;
    }
};
Time Complexity: O(n)
Space Complexity: O(1)



/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
