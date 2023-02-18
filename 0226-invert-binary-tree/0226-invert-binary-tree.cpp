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
    TreeNode* solve(TreeNode* node){
        if(!node)return nullptr;
        TreeNode* l = solve(node->left);
        TreeNode* r = solve(node->right);
        node->left= r;
        node->right= l;
        // TreeNode* temp= l;
        // l = r;
        // r = temp;
        return node;
    }
    
    
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};