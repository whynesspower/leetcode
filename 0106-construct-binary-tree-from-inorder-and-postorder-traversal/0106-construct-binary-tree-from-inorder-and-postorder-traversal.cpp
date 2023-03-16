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
 unordered_map<int,int>ump;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int &rootIdx,int left,int right)
    {
        if(left>right)
        {
            return NULL;
        }
  
        int pivot=ump[postorder[rootIdx]];
        rootIdx--;
        TreeNode* node=new TreeNode(inorder[pivot]);
        
        node->right=build(inorder,postorder,rootIdx,pivot+1,right);
        
        node->left=build(inorder,postorder,rootIdx,left,pivot-1);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int rootIdx=postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
        {
            ump[inorder[i]]=i;
        }
        
        return build(inorder,postorder, rootIdx, 0,inorder.size()-1);
        
    }
};