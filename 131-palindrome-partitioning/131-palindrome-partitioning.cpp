class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> path;
        temp(0, s, path, ans);
        return ans;
    }
    
    void temp(int index, string s, vector<string>&path, vector<vector<string>>&ans){
        
        if(index==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPlaindrome(s, index, i)){
                path.push_back(s.substr(index, i-index+1));
                temp(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }

    
    bool isPlaindrome(string s, int l, int r){
        while(l<=r){
            if(s[l++]!=s[r--]){
                return false;
            }
        }
        return true;
    }
};