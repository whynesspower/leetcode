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

    int maxLevelSum(TreeNode* root) {
        vector<vector<int>>nodes;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>t;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                t.push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            nodes.push_back(t);
        }
        int ans=INT_MIN;
        int res=0;
        for(int i=0;i<nodes.size();i++){
            int curr=0;
            for(int j=0;j<nodes[i].size();j++){
                curr+=nodes[i][j];
            }
            if(curr>ans){
                ans=max(ans, curr);
                res=i;
            }
            // ans=min(ans, curr);
        }
        return res+1;
    }
};