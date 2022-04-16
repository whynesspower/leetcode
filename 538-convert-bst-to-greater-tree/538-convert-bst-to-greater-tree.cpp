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

    private: 
        vector<int>sum;
        vector<int>presum;
    
    public:
    void add(TreeNode* root){
        if(!root) return;
        sum.push_back(root->val);
        add(root->left);
        add(root->right);
    }
    int find(int x){
        int low = 0, high =sum.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(sum[mid]==x){
                return mid;
            }
            else if(sum[mid]< x){
                low= mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
    
    void edit(TreeNode* root){
        if(!root) return;
        int i= find(root->val);
        root->val= presum[i];
        edit(root->left);
        edit(root->right);
        
    }
    
    void fill(){
        sort(sum.begin(), sum.end());
        presum.resize(sum.size());
        presum[sum.size()-1]=sum[sum.size()-1];
        for(int i=sum.size()-2;i>=0;i--){
            presum[i]=presum[i+1]+ sum[i];
            cout<<presum[i]<<" ";
        }
        return;
    }
    
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        add(root);
        fill();
        edit(root);
        return root;
        
    }
};