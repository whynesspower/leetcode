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
    int ans=0;
    int currsize(TreeNode* root){
        if(root==NULL) return 0;
        else{
            return 1+currsize(root->left)+currsize(root->right);
        }
    }
    int currsum(TreeNode* root){
        if(root==NULL) return 0;
        int xx= root->val + currsum(root->left)+ currsum(root->right);
        return xx;
    }
    void post(TreeNode* root){
        if(root==NULL)return;
        else{
            post(root->left);
            int a = currsum(root);
            int b = currsize(root);
            if(a/b==root->val) ans++;
            post(root->right);
            
        }
    }
    int averageOfSubtree(TreeNode* root) {
        post(root);    
        
        return ans;
       
    }
};