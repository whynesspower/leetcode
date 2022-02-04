class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0, maxlen=0, sum=0;
        for(int i=0;i<nums.size();i++){
            sum+= (nums[i]==0)?-1:1;
            if(sum==0){
                ans=i+1;
            }
            if(mp.find(sum)!=mp.end()){
                ans=max(ans, i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return ans;
    }
    
};