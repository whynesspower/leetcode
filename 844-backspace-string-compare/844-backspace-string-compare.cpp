class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> st2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(!st.empty())st.pop();
            }
            else{
                st.push(s[i]);
            }    
        }
        
        
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(!st2.empty())st2.pop();
            }
            else{
                st2.push(t[i]);
            }    
        }
        
        string temp="", temp2="";
        
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        while(!st2.empty()){
            temp2+=st2.top();
            st2.pop();
        }
        
        return temp==temp2;
        
    }
};