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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*>s1,s2;
        vector<vector<int>>ans;
        if(!root) return ans;
        s1.push(root);
        vector<int>temp;
        while(!s1.empty() or !s2.empty())   { 
           while(!s1.empty()){
                TreeNode* a= s1.top();
                s1.pop();
                temp.push_back(a->val);
                if(a->left) s2.push(a->left);
                if(a->right) s2.push(a->right);
            }
            if(temp.size()!=0)
            ans.push_back(temp);
            temp.clear();
            while(!s2.empty()){
                TreeNode *a = s2.top();
                s2.pop();
                temp.push_back(a->val);
                if(a->right) s1.push(a->right);
                if( a->left) s1.push(a->left);
            }
            if(temp.size()!=0)
            ans.push_back(temp);
            temp.clear();
        }    
        return ans;
    }
};