class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre1(n, 0);
        vector<int>pre2(n, 0);
        pre1[0]=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                pre1[i]=1;
            }
        }
        
        for(int i=1;i<n;i++){
            pre2[i]=pre2[i-1]+pre1[i-1];
        }
        
        vector<int>post1(n, 0);
        vector<int>post2(n, 0);
        
        post1[0]=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                post1[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            post2[i]=post2[i+1]+post1[i+1];
        }
        
        vector<int> ans;
        for(int i=k;i<(n-k);i++){
            int left=i-k;
            int right=i-1;
            int lef=i;
            int rig=i+k-1;
            if((pre2[left]==pre2[right]) and (post2[lef]==post2[rig])){
                ans.push_back(i);
            }
        }
        return ans;
    }
};