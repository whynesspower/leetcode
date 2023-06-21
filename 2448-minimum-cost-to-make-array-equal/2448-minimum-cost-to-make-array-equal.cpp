class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long n=nums.size();
        vector<long long>s1(n);
        vector<long long>s2(n);
        vector<long long>p1(n);
        vector<long long>p2(n);
        vector<pair<long long,long long>>vec;
        for(long long i=0;i<n;i++){
            vec.push_back({nums[i], cost[i]});
        }
        sort(begin(vec),end(vec));
        p1[0]=vec[0].second;
        p2[0]=vec[0].second*vec[0].first;
        s1[n-1]=vec[n-1].second;
        s2[n-1]=vec[n-1].second*vec[n-1].first;
        for(long long i=1;i<n;i++){
            p1[i]=p1[i-1];
            p2[i]=p2[i-1];
            p1[i]+=vec[i].second;
            p2[i]+=(vec[i].second*vec[i].first);
        }

        for(long long i=n-2;i>=0;i--){
            s1[i]=s1[i+1];
            s2[i]=s2[i+1];
            s1[i]+=(vec[i].second);
            s2[i]+=(vec[i].first*vec[i].second);
        }

        long long ans=LONG_MAX;
        for(long long i=0;i<n;i++){
            long long currcost=0;
            if(i>0){
                currcost+= (vec[i].first*(p1[i-1])-p2[i-1]);
            }
            if(i<n-1){
                currcost+= (s2[i+1]-vec[i].first*(s1[i+1]) );
            }
            ans=min(ans, currcost);
        }
        return ans;
    }
};