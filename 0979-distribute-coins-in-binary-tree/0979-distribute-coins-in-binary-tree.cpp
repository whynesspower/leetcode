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
    int solve(int &ans, TreeNode* root){
        if(!root)return 0;
        int a = solve(ans, root->left);
        int b = solve(ans, root->right);
        ans+= abs(a);
        ans+= abs(b);
        int c = root->val + b+ a -1;
        return c; 
    }
    
    int distributeCoins(TreeNode* root) {
        int ans=0;
        solve(ans, root);
        return ans;
    }
};