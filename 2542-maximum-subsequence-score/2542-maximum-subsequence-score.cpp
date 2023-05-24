#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>pairs;
        
        priority_queue<ll,vector<ll>, greater<ll>>pq;
        for(int i=0;i<nums1.size();i++){
            pairs.push_back({nums2[i], nums1[i]});
        }
        sort(rbegin(pairs), rend(pairs));
        ll sum=0;
        ll ans=INT_MIN;
        for(auto &[x,y]:pairs){
            pq.push(y);
            sum+=y;
            // int mini=min(mini,x );
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans=max(ans, sum*x);
            }
            
        }
        return ans;
    }
};