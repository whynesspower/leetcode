class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        for(int i=0;i<ops.size();i++){
            
            if(ops[i]=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c = a+b;
                st.push(b);
                st.push(a);
                st.push(c);
            }
            else if(ops[i]=="D"){
                int a = st.top();
  
                int b = 2*st.top();

                st.push(b);
            }
            else if(ops[i]=="C"){
                st.pop();
            }
            else{
                int a = stoi(ops[i]);
                st.push(a);
            }
        }
        
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }
};