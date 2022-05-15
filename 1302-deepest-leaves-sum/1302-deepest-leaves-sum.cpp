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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        else{
            return max(height(root->left), height(root->right))+1;
        }
    }
    
    int sum2=0;
    
    void AtDistK(TreeNode* root, int k){
        
        if(k==0 and root){
            sum2 +=root->val;
            return;
        }
        if(root==NULL)return;
        else{
            AtDistK(root->left, k-1);
            AtDistK(root->right, k-1);
        }
    }
    
    
    int deepestLeavesSum(TreeNode* root) {
        int k= height(root);
        AtDistK(root, k-1);
        return sum2;
    }
    
};