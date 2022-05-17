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
private:
    // int TargetValue;
    TreeNode* FinalAns;

public:
    void findTargetValue(TreeNode* cloned, int TargetValue){
        if(cloned==NULL) return;
        findTargetValue(cloned->left, TargetValue);
        if(cloned->val==TargetValue){
            FinalAns=cloned;
        }
        findTargetValue(cloned->right, TargetValue);
    }
    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        findTargetValue(cloned, target->val);
        return FinalAns;
    }
};