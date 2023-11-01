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
    vector<int>nodes;
    vector<int>dfs(TreeNode* root){
        if(!root)return nodes;
        if(root->left)dfs(root->left);
        nodes.push_back(root->val);
        if(root->right)dfs(root->right);
        return nodes;
    }

    vector<int> findMode(TreeNode* root) {
        // non-decreasing order
        int maxFreq=INT_MIN;
        vector<int>nodes=dfs(root);
        int n=nodes.size();
        int i=0;
        unordered_map<int,int>mp;
        for(auto x: nodes){
            mp[x]++;
            maxFreq=max(maxFreq, mp[x]);
        }
        vector<int>ans;
        for(auto x: mp){
            if(x.second==maxFreq)ans.push_back(x.first);
        }
        return ans;
    }
};