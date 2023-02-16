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
    int level[1000000]={};// gives level of the node 
    int depth[1000000]={};// gives depth of the node
    int d1[1000000]={};// largest depth at "i"th level 
    int d2[1000000]={};// second largest depth at "i"th level
    
    int height(TreeNode* node, int l){
        if(!node) return 0;
        level[node->val]=l;
        depth[node->val]= 1+ max(height(node->left, l+1), height(node->right, l+1));
        if(d1[l]<depth[node->val]){
            d2[l]=d1[l];
            d1[l]=depth[node->val];
        }
        else if(d2[l]<depth[node->val]){
            d2[l]=depth[node->val];
        }
        return depth[node->val];
    }
    
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root, 0);
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int sum=0;
            int a= queries[i];
            sum+= level[a];
            int d= depth[a];
            if(d==d1[level[a]]){
                sum+=d2[level[a]];
            }
            else{
                sum+=d1[level[a]];
            }
            ans.push_back(sum-1);
        }
        return ans;
    }
};