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
public:
    void preorder(TreeNode* root, vector<string>&ans, string t ){
        if(root->left==NULL and root->right==NULL){
            ans.push_back(t);
        }
        if(root->left) preorder(root->left, ans,   t+ "->"+  to_string(root->left->val));
        if(root->right) preorder(root->right, ans,t+ "->"+  to_string(root->right->val));
    }

        
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        preorder(root, ans, to_string(root->val));
        return ans;
    }
};