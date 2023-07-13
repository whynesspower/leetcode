class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        queue<int>q;
        int n=numCourses;
        vector<int>outdegree(n, 0);
        
        vector<int>AdjList[n];
        // AdjList[i] means the list of all the nodes which are pointing to the
        // ith node 
        for(int i=0;i<p.size();i++){
            int a= p[i][0];
            int b= p[i][1];
            // a is pointing to b
            AdjList[b].push_back(a);
            outdegree[a]++;
        }
        for(int i=0;i<n;i++){
            if(outdegree[i]==0) q.push(i);
        }
        int cnt=0;
        while(q.size()){
            int a= q.front();
            q.pop();
            cnt++;
            for(auto x: AdjList[a]){
                outdegree[x]--;
                if(outdegree[x]==0) q.push(x);
            }
        }
        return cnt==n;
    }
};