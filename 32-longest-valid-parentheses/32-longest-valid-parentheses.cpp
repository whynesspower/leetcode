class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(st.size()){
                    s[st.top()]=s[i]='*';
                    st.pop();
                    
                }
            }
        }
        int currans=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*') currans++;
            else{
                ans=max(ans,currans);
                currans=0;
            }
        }
        return max(ans, currans);
        
    }
};