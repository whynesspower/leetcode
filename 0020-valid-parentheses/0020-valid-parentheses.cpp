class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        // if(s[0]==']' or s[0]==')' or s[0]=='}') return false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')st.push(s[i]);
            else{
                if(st.size()==0) return false;
                char a= st.top();
                st.pop();
                if( s[i]==')' and a!='('){
                    return false;
                }
                if(s[i]=='}' and a!='{') return false;
                if(s[i]==']' and a!='[') return false;
            }
        }
        if(st.size()!=0) return false;
        return true;
    }
};