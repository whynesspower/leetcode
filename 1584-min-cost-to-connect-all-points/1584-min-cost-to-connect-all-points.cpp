class Solution {
    
    public:
    
    
    int find(vector<int>& parents, int i){
        if(i==parents[i]){
            return i;
        }
        return parents[i]=find(parents, parents[i]);
    }
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();    
        vector<int>parents(n);
        iota(parents.begin(), parents.end(), 0);
        int ans=0;
        int i=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i==j){
                    continue;
                }
                int c= abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                pq.push({c, i, j});    
            }
        }
     
        while(i!=n-1){
            vector<int>edge= pq.top();
            pq.pop();
            int p1= find(parents,edge[1]);
            int p2= find(parents, edge[2]);
            if(p1!=p2){
                ans+=edge[0];
                parents[p1]=p2;
                i++;
            }
        }
        return ans;
        
        
        
    }
    
        
    
    
    
};
