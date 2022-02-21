class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int a,b=INT_MIN;
        for(auto it:mp){
            if(it.second>b){
                b=it.second;
                a=it.first;
            }
        }
        
        return a;
        
    }
};