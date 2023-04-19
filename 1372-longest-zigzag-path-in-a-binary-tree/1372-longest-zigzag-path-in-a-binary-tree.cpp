class Solution {
public:
    map<pair<TreeNode*,int>,int> m;
    int count(TreeNode* root,int dir){
        if(!root){
            return 0;
        }
        if(m[{root,dir}]!=0){
            return m[{root,dir}];
        }
        int c = 0;
        if(dir){
            c = 1 + count(root->right,0);
        }
        else{
            c = 1 + count(root->left,1);
        }
        return m[{root,dir}] = c;
    }
    void solve(TreeNode* root,int &ans){
        if(!root){
            return;
        }
        int countRight = count(root,1);
        int countLeft = count(root,0);
        ans = max(ans,max(countRight,countLeft));
        solve(root->left,ans);
        solve(root->right,ans);
    }
    int longestZigZag(TreeNode* root){
       int ans = 0;
       solve(root,ans);
       return ans-1;
    }
};