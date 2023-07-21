// class Solution {
// public:
//     int findNumberOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         // length distance, frequency of  that distance
//         map<int,int, greater<int>>mp; 
//         vector<pair<int,int>>dp(n);
//         // pair int,int --> length of lis till ith index, freq of that lis till ith index
//         dp[0].first=1;
//         dp[0].second=1;
        
//         for(int i=1;i<n;i++){
//             for(int j=0;j<i;j++){
//                 bool flag=false;
//                 if(nums[i]>nums[j] and dp[i].first<=dp[j].first+1){
//                     if(dp[i].first==(dp[j].first+1)){
//                         dp[i].first=dp[j].first+1;
//                         dp[i].second=dp[j].second+1;
//                     }
//                     else{
//                         dp[i].first=dp[j].first+1;
//                         dp[i].second=1;
//                     }
                    
//                     // flag=true;
//                     // mp[dp[i]]++;
//                 }
//             }
//         }
        
//         int maxLength=INT_MIN;
//         int maxLengthFreq=INT_MIN;
//         for(int i=0;i<dp.size();i++){
//             if(maxLength<=dp[i].first){
//                 if(maxLength==dp[i].first){
//                     maxLengthFreq=max(maxLengthFreq, dp[i].second);
//                 }
//                 else{
//                     maxLength=dp[i].first;
//                     maxLengthFreq=dp[i].second;
//                 }
//             }
//         }
//         return maxLengthFreq;
      
//     }
// };



class Solution {
public:
    
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> lis(n,1);  // stores length of longest sequence till i-th position
        vector<int> count(n,1);  // stores count of longest sequence of length lis[i]
        int maxLen = 1;  // maximum length of lis
		
		// O(N^2) DP Solution
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(lis[j] + 1 > lis[i]){ // strictly increasing
                        lis[i] = lis[j] + 1;
                        count[i] = count[j];
                    } 
					 // this means there are more subsequences of same length ending at length lis[i]
					else if(lis[j]+1 == lis[i]){ 
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen,lis[i]);
        }
        
        int numOfLIS = 0;
        // count all the subseq of length maxLen
        for(int i=0;i<n;i++){
            if(lis[i]==maxLen)
                numOfLIS += count[i];
        }
            
        return numOfLIS;
    }
};