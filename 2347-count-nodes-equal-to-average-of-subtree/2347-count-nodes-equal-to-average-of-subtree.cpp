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
    int ans=0;
    pair<int,int> dfs(TreeNode* root){
        pair<int, int> p={0,0};
        if(!root) return p;
        int currSum=root->val;
        int numNodes=1;
        if(root->left){
            pair<int,int>t= dfs(root->left);
            currSum+=t.first;
            numNodes+=t.second;
        }
        if(root->right){
            pair<int,int>t=dfs(root->right);
            currSum+=t.first;
            numNodes+=t.second;
        }
        if((currSum/numNodes)==( root->val)){
            cout<<(root->val)<<" ";
            ans++;
        }
        p= {currSum, numNodes};
        return p;
    }
    int averageOfSubtree(TreeNode* root) {
        // dfs will return a pair of 
        // int, int which will have 
        // number of nodes in the subtree, sum of all the elements of the subtreee
        dfs(root);
        return ans;
    }
};