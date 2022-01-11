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
    

    void preorder(vector<string>&temp, TreeNode *root, string t){
        
        if(root->left==NULL and root->right==NULL){
            temp.push_back(t);
        }   
        if(root->left) preorder(temp, root->left, t+ to_string(root->left->val));
        if(root->right) preorder(temp, root->right, t+ to_string(root->right->val));
    }
    
    int func(string &x){
        int ans=0;
        for(int i=x.length()-1; i>=0;i--){
            int pp= x[i]=='0'?0:1;
            int j=x.length()-1 -i;
                ans+= pp*(1<<j);
        }
        return ans;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        vector<string> temp;
        preorder(temp, root, to_string(root->val));
        int ans=0;
        for(auto x:temp){
            ans+= func(x);
        }
        return ans;
    }
};