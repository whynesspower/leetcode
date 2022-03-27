class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<mat.size();i++){
            int count1=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    count1++;
                    
                }
            }
            v.push_back(make_pair(count1, i));
        }
    
    sort(v.begin(), v.end());
    vector<int> ans;
    for(int i=0;i<k;i++){
        int temp= v[i].second;
        ans.push_back(temp);
    }
    return ans;
    }
};