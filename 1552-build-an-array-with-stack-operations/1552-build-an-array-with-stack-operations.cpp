class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int i=0;
        int val=1;
        while(val<=n and (i<target.size())){
            if(target[i]==val){
                i++;
                ans.push_back("Push");
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
                
            }
            val++;
        }
        return ans;
    }
};