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

    
    
    private: int curr_sum=0;
    
    public:

    
    void travel(TreeNode* root){
        
        if(!root) return ;

        bstToGst(root->right);
        curr_sum+= root->val;
        root->val= curr_sum;
        bstToGst(root->left);
        
    }
    
    
    TreeNode* bstToGst(TreeNode* root) {
    
        travel(root);
        return root;
    
    }
};