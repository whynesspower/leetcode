/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // first lets copy the normal linkedlist
        // then create a hashtable with node*, node* 
        // old node address-> new node address
        
        unordered_map<Node*, Node*>oldNewMapping;
        Node*curr=head;
        Node* newHead= NULL;
        Node*ans=NULL;
        while(curr!=NULL){
            Node* nextNode= new Node(curr->val);
            nextNode->random=curr->random;
            if(newHead==NULL){
                newHead=nextNode;
                // newHead->random=curr->random;
                ans=newHead;
                newHead->next=NULL;
                oldNewMapping[curr]=newHead;
            }
            else{
                newHead->next=nextNode;
                newHead=newHead->next;
                oldNewMapping[curr]=newHead;
            }
            curr=curr->next;   
        }
        curr=ans;
        while(curr!=NULL){
            Node* newRandom=oldNewMapping[curr->random];
            curr->random=newRandom;
            curr=curr->next;
        }
        
        return ans;
    }
};