class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n= profits.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({capital[i], profits[i]});
        }
        sort(p.begin(), p.end());
        int ans=0;
        int i=0;
        priority_queue<int>pq;
        while(k--){
            while(i<n and p[i].first<=w){
                // w+=p[i][1];
                pq.push(p[i].second);
                i++;
            }
            if(pq.empty()) break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};