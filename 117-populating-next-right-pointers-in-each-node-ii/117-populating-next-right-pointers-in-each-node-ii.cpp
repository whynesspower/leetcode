/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void helper(Node * root){
        if(root==NULL ) return;
        queue<Node* >q;
        q.push(root);
        q.push(NULL);
        Node *prev=NULL;
        while(q.size()>1){
            Node *curr= q.front();
            q.pop();
            if(curr==NULL){
                prev->next=NULL;
                q.push(NULL);
                prev=NULL;
                continue;
            }
            if(prev){
                prev->next=curr;
                prev=curr;
            }
            else{
                prev=curr;
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    
    Node* connect(Node* root) {
        helper(root);
        return root;
    }
};