class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        
        for(int i=0;i<s.size();i++){
            if(st.empty() or st.top().first!=s[i]){
                st.push({s[i], 1});
            }
            else if (st.top().first==s[i] and st.top().second!=k){
                st.push({s[i], st.top().second+1});
            }
            if(st.top().second==k){
                int kk=k;
                while(kk){
                    st.pop();
                    kk--;
                }
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top().first;
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};