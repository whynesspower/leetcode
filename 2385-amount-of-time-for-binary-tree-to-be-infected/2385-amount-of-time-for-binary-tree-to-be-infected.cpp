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
    TreeNode* target;
    unordered_map<TreeNode*, vector<TreeNode* >>mp;
    
    unordered_map<TreeNode*, int>mp2;
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
    void search(int s, TreeNode* root){
        if(!root) return;
        if(root->val==s){
            target=root;
            return;
        }
        if(!root) return;
        search(s, root->left);
        search(s, root->right);
    }
    
    void dfs(TreeNode* node , int i){
        if(node==nullptr) return;
        vis.insert(node);
        // if(i==k) ans.push_back(node->val);
        // mp2 has time to burn the current node
        
        mp2[node]=i;
        for(auto x: mp[node]){
            if(vis.find(x)==vis.end()){
                dfs(x, i+1);   
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        search(start, root);
        buildmap(root, nullptr);
        dfs(target, 0);
        int ans=INT_MIN;
        for(auto x:mp2){
            ans=max(ans, x.second);
        }
        return ans;
    }
};