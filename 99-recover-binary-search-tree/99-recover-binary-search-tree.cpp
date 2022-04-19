/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    private: 
        TreeNode* first, *second, *prev;
    
    
    public:
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(first==NULL and (prev==NULL or prev->val >= root->val)){
            first=prev;
        }
        if(first!=NULL and prev->val >= root->val){
            second=root;
        }
        prev=root;
        
        inorder(root->right);
    }
    
    
    
    void recoverTree(TreeNode* root) {
        if(!root) return;
        first=NULL;
        second=NULL;
        prev=NULL;
        inorder(root);
        int tempj = first->val;
        first->val=second->val;
        second->val= tempj;
    }
};