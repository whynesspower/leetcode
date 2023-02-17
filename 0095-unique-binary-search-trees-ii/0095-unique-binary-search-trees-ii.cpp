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
    vector<TreeNode*> generateTrees(int n) {
        // if(n==0) return {};
        return solve(1, n);
    }
    vector<TreeNode*>solve(int start, int end)
    {
        
        vector<TreeNode*>ans;
        if(start> end){
            ans.push_back(nullptr);
            return ans;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode* >left= solve(start, i-1);
            vector<TreeNode* >right= solve(i+1, end);
            for(TreeNode* l: left){
                for(TreeNode* r: right){
                    TreeNode* temp=new TreeNode(i);
                    temp->left=l;
                    temp->right=r;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    
};