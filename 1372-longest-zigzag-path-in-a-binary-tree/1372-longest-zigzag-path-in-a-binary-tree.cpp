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
    unordered_map<TreeNode*, int>mp;
    // flag ---> true: go to right first
    // flag ---> false: go to left first
    int dfs2(TreeNode* root, bool flag){
        if(mp.find(root)!=mp.end()){
            return mp[root];
        }
        if(!root)return 0;
        int a= 0;
        if(flag){
            flag=!flag;
            a= dfs2(root->right, flag);
        }
        else{
            flag=!flag;
            a= dfs2(root->left, flag);
        }
        mp[root]=a+1;
        return mp[root];
    }
    
    void dfs(TreeNode* root){
        if(!root)return;
        int a= dfs2(root->left, true);
        int b= dfs2(root->right, false);
        mp[root]=max(a,b);
        
        dfs(root->left);
        dfs(root->right);
    }
    int longestZigZag(TreeNode* root) {
        dfs(root);
        int ans=INT_MIN;
        for(auto x: mp){
            ans=max(x.second, ans);
        }
        return ans;
    }
};