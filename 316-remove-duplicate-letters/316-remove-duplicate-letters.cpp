class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>dict(256, 0);
        vector<bool>visited(256, false);
        
        for(auto x:s){
            dict[x]++;
        }
        
        string ans="0";
        
        for( auto x: s){
            dict[x]--;
            if(visited[x]) continue;
                
            while(x < ans.back() and dict[ans.back()]){
                visited[ans.back()]=false;
                ans.pop_back();
            }
            
            ans+=x;
            visited[x]=true;
        }
        return ans.substr(1);
    }
};