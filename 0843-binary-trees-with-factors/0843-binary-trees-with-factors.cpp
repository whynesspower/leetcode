
#define ll long long
class Solution {
public:
    int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        //  [2,4,5,10,50] --> 14
        //   1,2,1,3, 7
        //   1 2 1 2 3 
        //   4,8,10, 20, 100
        //   8 16 20 40 200
        //   10,20 20 50 250
        //   20 40 50 100 500
        //   100 200 250 500 2500

        int n=arr.size();
        sort(arr.begin(), arr.end());
        vector<int>dp(n, 1);
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[arr[i]]=i;
        }
        for(int i=0;i<n;i++){
            // int currFreq=0;
            for(int j=0;j<i;j++){
                ll currFreq=1;
                if((arr[i]%arr[j])==0){
                    currFreq=(((currFreq)%mod)*(( dp[freq[arr[j]]])%mod))%mod;
                    ll rem=arr[i]/arr[j];
                    // cout<<arr[i]<<" "<<arr[j]<<" "<<rem<<" "<<dp[freq[arr[j]]]<<" "<<dp[freq[rem]];
                    if(freq.find(rem)!=freq.end()){
                        
                        currFreq=(((currFreq)%mod)*((dp[freq[rem]])%mod))%mod; 
                    }
                    else{
                        currFreq=0;
                    }
                    // cout<<" "<<currFreq;
                }
                else{
                    continue;
                }
                dp[i]=(dp[i]+currFreq)%mod;
            }
            // cout<<" "<<currFreq<<endl;
            
            // if(i==3)cout<<currFreq<<" ";
        }
        ll ans=0;
        for(auto x:  freq){
            // cout<<x.first<<" "<<x.second<<endl;
        }


        for(int i=0;i<n;i++){
           
            cout<<dp[i]<<" ";
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};