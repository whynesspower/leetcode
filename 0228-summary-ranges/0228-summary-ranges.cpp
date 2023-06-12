class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>al;
         for(int i=0;i<nums.size();i++){
            int start=nums[i];
            while(i+1<nums.size() && nums[i]+1==nums[i+1])
                i++;
            
            if(start!=nums[i]){
                string a= to_string(start);
                string b= to_string(nums[i]);
                al.push_back(""+a+"->"+b);
            }
            else{
                string a= to_string(start);
                al.push_back(""+a);
            }
        }
        return al;
    }
};