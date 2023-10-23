class Solution {
public:
    vector<string>ans;
    bool isValid(string s){
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push(s[i]);
            else{
                if(st.empty()) return false;
                else{
                    st.pop();
                    continue;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }


    void dfs(int n, string currStr){
        if(currStr.size()==(2*n) and isValid(currStr)){
            ans.push_back(currStr);
            return;
        }
        else if(currStr.size()>(2*n)) return ;
        // vector<char>temp=;
        for(char x :{'(', ')'}){
            currStr=currStr+x;
            dfs(n, currStr);
            currStr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        dfs(n, "");
        return ans;    
    }
};