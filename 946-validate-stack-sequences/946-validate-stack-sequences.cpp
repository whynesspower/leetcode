class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int n=pushed.size();
        int i=0;
        int j=0;
        
        for(int i=0;i<n;i++){
            st.push(pushed[i]);

            while(j< n and !st.empty() and st.top()==popped[j]){
                st.pop();
                j++;
            }
            if(st.empty() and i==n-1){
                return true;
            }
        
        }
        
        return st.empty();
    }
};