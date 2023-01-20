class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            int n= ans.size();
            for(int j=0;j<n;j++){
                if(nums[i]>=ans[j].back()){
                    vector<int>temp=ans[j];
                    temp.push_back(nums[i]);
                    ans.push_back(temp);
                }  
            }
            ans.push_back({nums[i]});
        }
        // unordered_set<vector<int>>st;
        sort(ans.begin(), ans.end());
        vector<vector<int>>ans2;
        if(ans[0].size()>=2) ans2.push_back(ans[0]);
        for(int i=1;i<ans.size();i++){
            if(ans[i]==ans[i-1]) continue;
            if(ans[i].size()>=2){
                ans2.push_back(ans[i]);
            }
        }   
        return ans2;
    }
};