class Solution {
public:
    // return maximum time required to inform all children from ith index  
    int dfs(vector<int>& informTime, int i,unordered_map<int,vector<int>>&mp, int n ){
        if(mp[i].size()==0) return informTime[i];
        
        int ans=INT_MIN;
        // going through all the children of i
        for(auto x: mp[i]){ 
            ans=max(ans,informTime[i]+dfs(informTime, x, mp, n));    
        }
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {  
        unordered_map<int,vector<int>>mp;
        // employer, children
        for(int i=0;i<manager.size();i++){
            if(manager[i]==-1){
                // mp[i].push_back();
                continue;
            }
            else{
                mp[manager[i]].push_back(i);
            }
        }
        return dfs(informTime, headID, mp, n);
    }
};