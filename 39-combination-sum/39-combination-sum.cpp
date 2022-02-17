class Solution {
public:
    
    void func(vector<vector<int>>&ans, vector<int>&temp, int target, int index, vector<int>&candi){
        if(index==candi.size() ){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(candi[index]<=target){
            temp.push_back(candi[index]);
            func(ans, temp, target-candi[index], index, candi);
            temp.pop_back();
        }
        
        func(ans, temp, target, index+1, candi);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        func(ans,temp, target, 0 , candidates);
        
        return ans;
    }
};