class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int>st;
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        
        // row wise traversal
        for(int i=0;i<m;i++){
            string t="";
            for(int j=0;j<n;j++){
                string a= to_string(grid[i][j]);
                t+=a;
                t+="+";
            }
            st[t]++;
        }
        
        // col wise traversal 
        for(int j=0;j<n;j++){
            string t="";
            for(int i=0;i<m;i++){
                string a= to_string(grid[i][j]);
                t+=a;
                t+="+";
            }
            if(st.find(t)!=st.end()){
                ans+=st[t];
                cout<<t<<" ";
            }
        }
        return ans;
    }
};