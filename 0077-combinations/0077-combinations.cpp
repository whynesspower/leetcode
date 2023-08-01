class Solution {
public:
    vector<vector<int>>ans;
    int K;
    void solve(int n, int currindx, int k, vector<int>&currArray){
        if(currindx>n+1) return;
        
        if(k==0){
            ans.push_back(currArray);
            return;
        }
        currArray.push_back(currindx);
        solve(n, currindx+1, k-1,currArray);
        currArray.pop_back();
        solve(n, currindx+1, k,currArray);
    }
    vector<vector<int>> combine(int n, int k) {
        // this->K=k;
        for(int i=1;i<=n;i++){
            vector<int>currArray;
            currArray.push_back(i);
            solve(n, i+1, k-1, currArray);
        }
        return ans;
    }
};