class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool> visited(n,0);
        visited[0]=true;
        queue<pair<int,int>>q;
        q.push({0,0});
        
        while(!q.empty()){
            pair<int,int>temp=q.front();
            q.pop();
            int u=temp.first;
            int d=temp.second;
            if(u==n-1){
                return d;
            }
            else {
                if(u>0 and !visited[u-1]){
                    visited[u-1]=true;
                    q.push({u-1, d+1});
                }
                if(u+1<n and !visited[u+1]){
                    visited[u+1]=true;
                    q.push({u+1, d+1});
                }
                for(auto v:mp[arr[u]]){
                    if(!visited[v]){
                        q.push({v, d+1});
                        visited[v]=true;
                    }
                }
                mp[arr[u]]={};
            }
        }
        return INT_MAX;
    }
};