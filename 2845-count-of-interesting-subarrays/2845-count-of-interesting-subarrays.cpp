#define ll long long
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        
        ll n=nums.size();
        
        vector<ll>prefix(n);
        for(ll i=0;i<n;i++){
            ll curr=nums[i]%mod==k;
            if(i==0){
                prefix[i]=curr;
            }
            else{
                prefix[i]=prefix[i-1]+curr;
            }
            cout<<prefix[i]<<" ";
        }
        
        unordered_map<ll,ll>countRemainders;
        countRemainders[0]=1;
        ll ans=0;
        
        for(ll i=0;i<n;i++){
            ans+=countRemainders[((prefix[i]+mod-k)%mod)];
            countRemainders[prefix[i]%mod]++;   
        }
        
        return ans;
    }
};