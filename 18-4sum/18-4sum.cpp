class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        int n=nums.size();
        if(nums.empty()) return ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int front=j+1;
                int rear=n-1;
                int target2= target- nums[i]-nums[j];
                while(front< rear){
                    if(target2 > nums[front]+ nums[rear]){
                        front++;
                    }
                    else if(target2 < nums[front]+nums[rear]){
                        rear--;
                    }
                    else{
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[front]);
                        temp.push_back(nums[rear]);
                        ans.push_back(temp);
                        while(front< rear and nums[front]== temp[2]) front++;
                        while(front<rear and nums[rear] == temp[3] )rear--;
                    }
                }
                while(j+1< n and nums[j+1]==nums[j]) j++;
            }
            while(i+1< n and nums[i+1]== nums[i]) i++;
        }
        return ans;
        
        
    }
};