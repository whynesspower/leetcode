static const auto io_sync_off = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {    
public:

    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>>mat(n, vector<int>(n, 0));
        int m=q.size();
        vector<vector<int>>prefix(n, vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            int row1=q[i][0];
            int row2=q[i][2];
            int col1=q[i][1];
            int col2=q[i][3];
            for(int j=row1;j<=row2;j++){
                prefix[j][col1]+=1;
                if(col2+1<n)prefix[j][col2+1]-=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                // if(j==0) prefix[i]
                prefix[i][j]+=prefix[i][j-1];
            }
        }
        return prefix;
    }
};
