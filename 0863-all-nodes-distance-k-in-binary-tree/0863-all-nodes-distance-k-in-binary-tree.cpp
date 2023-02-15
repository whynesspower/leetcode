/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode* >>mp;
    vector<int>ans;
    unordered_set<TreeNode*>vis;
    void buildmap(TreeNode* node, TreeNode* prev){
        if(node==nullptr) return;
        if(mp.find(node)==mp.end() and prev!=nullptr){
            mp[node].push_back(prev);
            mp[prev].push_back(node);
        }
        buildmap(node->left, node);
        buildmap(node->right, node);
    }
    void dfs(TreeNode* node, int k , int i){
        if(node==nullptr) return;
        vis.insert(node);
        if(i==k) ans.push_back(node->val);
        for(auto x: mp[node]){
            if(vis.find(x)==vis.end()){
                dfs(x, k, i+1);   
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildmap(root, nullptr);
        // mp has adj list
        dfs(target, k, 0);
        return ans;
    }
};