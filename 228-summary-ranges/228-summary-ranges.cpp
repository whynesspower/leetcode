class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<vector<int>>temp1;
        vector<int>temp2;
        bool flag=false;
        for(int i=0;i<nums.size();i++){
            temp2.clear();
            int a=nums[i];
            temp2.push_back(nums[i]);
            while( (i<nums.size()-1) and nums[i+1]==(1+nums[i])){
                
                // if(i==nums.size()-1) flag=true;
                i++;
            }
            if(a!=nums[i])temp2.push_back(nums[i]);
            temp1.push_back(temp2);
        }
        vector<string> ans;
        
        for(int i=0;i<temp1.size();i++){
            string temp3="";
            for(int j=0;j<temp1[i].size();j++){
                temp3+=to_string(temp1[i][j]);
                if(j!=temp1[i].size()-1) temp3+="->";
            }
            ans.push_back(temp3);
        }
        
        
        return ans;
    }
};