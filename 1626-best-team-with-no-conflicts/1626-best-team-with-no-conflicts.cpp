class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>vec;
        for(int i=0;i<ages.size();i++){
            vec.push_back({ages[i], scores[i]});
        }
        sort(vec.begin(), vec.end());
        int ans=INT_MIN;
        int n= ages.size();
        vector<int>dp(n,0);
        // dp of i will give the maxi sum we get from ith to last index
        // such that sabka sum less equals to ith ka score ho
        
        for(int i=n-1;i>=0;i--){
            int currmax=0;
            for(int j=i;j<n;j++){
                if((vec[j].second>=vec[i].second))
                    currmax=max(currmax,dp[j]);
            }    
            currmax+=vec[i].second;
            dp[i]=currmax;
        }
        
//         for(int i=0;i<n;i++){
//             int currsum=vec[i].second;
//             int maxscoretillnow=vec[i].second;
//             for(int j=i+1;j<n;j++){
//                 if(vec[j].second>=vec[i].second and vec[j].second>=maxscoretillnow){
//                     currsum+=vec[j].second;
//                     maxscoretillnow=max(maxscoretillnow, vec[j].second);
//                 }
//             }
//             ans=max(currsum, ans);
//         }
        
        return *max_element(dp.begin(), dp.end());
    }
};