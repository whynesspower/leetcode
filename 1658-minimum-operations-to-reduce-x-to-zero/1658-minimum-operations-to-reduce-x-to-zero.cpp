class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0, j=0, sum=0;
        
        int ans1=INT_MIN;
        int n=nums.size();
        int sum1=0;
        for(int i=0;i<n;i++){
            sum1+=nums[i];
        }
        int k=sum1-x;
        if(k<0){
            return -1;
        }
        while(j<n){
            sum+=nums[j];
            if(sum<k){
                j++;
            }
            else if(sum==k){
                ans1=max(ans1, j-i+1);
                j++;
            }
            else if(sum>k){
                while(sum>k){
                    sum-=nums[i];
                    i++;   
                }
                if(sum==k){
                    ans1=max(ans1, j-i+1);
                }
                j++;
            }
        }
        if(ans1==INT_MIN or (sum1<x)){
            return -1;
        }
        return (n-ans1);
    }
};