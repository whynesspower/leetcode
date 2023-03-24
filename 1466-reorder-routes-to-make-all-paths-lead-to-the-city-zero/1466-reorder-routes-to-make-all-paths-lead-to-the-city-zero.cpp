class Solution {
public:
    multimap<int,int>mp;
    
    void dfs(int &cnt, vector<int>adj[], int s, vector<bool>&vis,  vector<int>oneside[] ){
        vis[s]=true;
        for(auto x: adj[s]){
            if(!vis[x]){
                for(auto y: oneside[x]){
                    if(!vis[y]){
                        cout<<y<<" ";
                        cnt++;
                    }
                }
                // cnt+= oneside[x].size();
                vis[x]=true;
                dfs(cnt, adj, x, vis, oneside);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        vector<int>OneSide[n];
        for(auto x: connections){
            int a= x[0];
            int b= x[1];
            // mp[a]=b;
            OneSide[a].push_back(b);
            mp.insert(pair<int, int>(a,b));
            // a --> b   
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // for(auto x: OneSide){
        //     for(auto y: x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int cnt=0;
        vector<bool>vis(n, false);
        for(auto y: OneSide[0]){
            cout<<y<<" ";
            cnt++;
        }
        dfs(cnt, adj, 0, vis, OneSide);
        return cnt;
    }
};