class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(auto c: num){
            while(st.empty()==false and k>0 and st.top()> c){
                st.pop();
                k--;
            }
            if(st.empty()==false or c!='0'){
                st.push(c);
            }
        }
        
        while(!st.empty() and k--){
            st.pop();
        }
        if(st.empty()){
            return "0";
        }
        string ans="";
        
        while(st.empty()==false){
            ans+=st.top();
            st.pop();
        }
        // cout<<ans<<endl;
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};