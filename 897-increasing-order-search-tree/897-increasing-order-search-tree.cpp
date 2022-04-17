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

    private: vector<int> v;
    public:
    void preorder(TreeNode* root){
        if(!root) return;
        preorder(root->left);
        v.push_back(root->val);
        preorder(root->right);
    }
    
    
    
    TreeNode* increasingBST(TreeNode* root) {
        preorder(root);
        TreeNode* root1= new TreeNode();
        TreeNode* ans = root1;
        for(int i=0;i<v.size();i++){
            root1->right= new TreeNode(v[i]);
            root1=root1->right;
        }
        root1->right=NULL;
        return ans->right;
    }
};