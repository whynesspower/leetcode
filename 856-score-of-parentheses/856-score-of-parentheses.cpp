class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int>st;
        int curr=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(curr);
                curr=0;
            }else{
                curr+=st.top() + max(curr, 1);
                st.pop();
            }
        }
        
        return curr;
    }
};