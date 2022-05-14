class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>g[n+1];
        for(int i=0;i<times.size();i++){
            g[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>distTo(n+1 , INT_MAX);
        distTo[k]=0;
        pq.push({0, k});
        while(!pq.empty()){
            int dist=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            for(auto it: g[prev]){
                int next=it.first;
                int nextDist=it.second;
                if(distTo[next] > distTo[prev] + nextDist){
                    distTo[next]= distTo[prev]+ nextDist;
                    pq.push({distTo[next], next});
                }
            }
            
        }
        int ans=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(distTo[i]==INT_MAX){
                return -1;
            }
            ans=max(ans, distTo[i]);
        }
        return ans;
    }
};