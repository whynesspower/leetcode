class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        vector<int>LeftOnes(n,0);
        LeftOnes[0]=nums[0]==0?0:1;
        vector<int>RightOnes(n,0);
        RightOnes[n-1]=nums[n-1]==0?0:1;
        for(int i=1;i<n;i++){
            if(nums[i]==0){
                LeftOnes[i]=0;
            }
            else{
                LeftOnes[i]=LeftOnes[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0){
                RightOnes[i]=0;
            }
            else{
                RightOnes[i]=RightOnes[i+1]+1;
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(i==0){
                    ans=max(ans, RightOnes[i+1]);
                }
                else if(i==n-1){
                    ans=max(ans, LeftOnes[i-1]);
                }
                else{
                    ans=max(ans, LeftOnes[i-1]+RightOnes[i+1]);
                }
            }
        }
        return ans==-1?n-1:ans;
    }
};