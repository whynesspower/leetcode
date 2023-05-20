class Solution {
public:
    void dfs(string s, string d,map<string, vector<pair<string, double>>>&mp, set<string>&v, double &ans, double temp  ){
        if(v.find(s)!=v.end()) return;
        else{
            v.insert(s);
            if(s==d){
                ans=temp;
                return  ;
            }
            else{
                for(auto a:mp[s]){
                    dfs(a.first, d, mp,v, ans,temp*a.second );
                }
            }
        }
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string, vector<pair<string, double>>>mp;
        for(int i=0;i<e.size();i++){
            mp[e[i][0]].push_back({e[i][1], v[i]});
            mp[e[i][1]].push_back({e[i][0], 1/v[i]});
        }
        
        vector<double>res;
        for(int i=0;i<q.size();i++){
            string s=q[i][0];
            string d=q[i][1];
            set<string>visited;
            double ans=-1.0;
            if(mp.find(s)!=mp.end()) 
               dfs(s, d, mp, visited,ans, 1.0 );
            res.push_back(ans);
        }
        return res;
    }
};