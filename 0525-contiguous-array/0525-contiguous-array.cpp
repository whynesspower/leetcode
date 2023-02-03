class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>mp; //sum, index
        int currsum=0;
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
            currsum+=(nums[i]==0?-1:1);
            if(currsum==0)ans=max(ans, i+1);
            if(mp.find(currsum)!=mp.end()){
                ans=max(ans, i-mp[currsum]);
            }
            else{
                mp[currsum]=i;
            }
        }
        
        return ans;
    }
};