class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int curr=1;
        int i=0;
        vector<string>ans;
        while(curr!=target.back() and i<target.size()){
            if(target[i]==curr){
                ans.push_back("Push");
                i++;
                curr++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
                curr++;
            }
        }
        if(curr==target.back()) ans.push_back("Push");
        return ans;
    }
};