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
    unordered_map<int, int>m;
    int index=0;
    TreeNode* solve(vector<int>&pre,vector<int>&in, int lo, int up){
        
        if(lo> up)return NULL;
        TreeNode* ans= new TreeNode(pre[index++]);
        if(lo==up)return ans;           
        int mid= m[ans->val];
        ans->left= solve(pre, in ,lo, mid-1);
        ans->right= solve(pre, in, mid+1, up);
        return ans;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        m.clear();
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;
        }
        TreeNode * root = solve(pre, in, 0, pre.size()-1);
        return root;
    }
};