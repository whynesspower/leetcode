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
    bool solve(TreeNode* a, TreeNode* b){
        if(!a and !b) return true;
        if ((!a and b) or (a and !b)) return false;
        if(a->val!=b->val) return false;
        bool aa= solve(a->left, b->left);
        bool bb= solve(a->right, b->right);
        if(aa and bb) return true;
        return false;
    }
    
    vector<TreeNode*> ans;
    unordered_set<TreeNode*>res;
    unordered_map<int, vector<TreeNode*>>mp;
    
    bool dfs(TreeNode* root){
        if(!root){
            return true;    
        }
        bool l= dfs(root->left);
        bool r= dfs(root->right);
        if(l and r){
            auto it=mp[root->val];
            if(it.size()==0){
                mp[root->val].push_back(root);
                return false;
            }
            vector<TreeNode*>temp=it;
            for(int i=0;i<temp.size();i++){
                if(solve(root, temp[i])){
                    res.insert(temp[i]);
                    return true;
                }
            }
        }
        mp[root->val].push_back(root);
        return false;
    }
    
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return ans;
        dfs(root);
        for(auto it:res){
            ans.push_back(it);
        }
        return ans;        
    }
};