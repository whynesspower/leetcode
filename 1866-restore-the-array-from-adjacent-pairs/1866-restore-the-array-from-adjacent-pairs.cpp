class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& a) {
        vector<int>ends;
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<a.size();i++){
            int p=a[i][0];
            int q=a[i][1];
            mp[p].push_back(q);
            mp[q].push_back(p);
        }
        for(auto x: mp){
            if(x.second.size()==1){
                ends.push_back(x.first);
            }
        }
        unordered_set<int>seen;
        // for(auto x: mp){
        //     for(auto y: mp[x.first]){
        //         if(y==ends[0|| y==ends[1]]){
        //             // mp[x.first].erase(y);
        //             mp[x.first].erase(std::remove(mp[x.first].begin(), mp[x.first].end(), y), mp[x.first].end());
        //         }
        //     } 
        // }
        // for(auto x: mp){
        //     cout<<x.first<<" ";
        //     for(auto y: mp[x.first]){
        //         cout<<y<<" ";
        //     } 
        //     cout<<endl;
        // }
        
        int prev=INT_MIN;
        int curr=ends[0];
        int n=a.size();
        int total=a.size()+1;
        vector<int>ans;
        ans.push_back(curr);
        seen.insert(curr);
        while(true){
            for(auto x: mp[curr]){
                if(seen.find(x)==seen.end()){
                    ans.push_back(x);
                    seen.insert(x);
                    if(ans.size()==total) return ans;
                    curr=x;
                }
            }
        }
        // ans.push_back(ends[1]);
        return ans;
    }
};