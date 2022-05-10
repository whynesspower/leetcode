class Solution {
public:
    vector<vector<int>>ans;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>combi;
        helper(k,n,combi);
        return ans;
    }
    
    void helper(int k, int n, vector<int>&combi){
        if(combi.size()==k and n==0){
            ans.push_back(combi);
            return;
        }
        if(combi.size()<k){
            for(int i=combi.empty()?1:combi.back()+1;i<=9;i++){
                if(n-i<0)break;
                combi.push_back(i);
                helper(k,n-i,combi);
                combi.pop_back();
            }
        }
    }
    
};