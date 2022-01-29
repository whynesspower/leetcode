class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int ans=0, curr, tp;
        for(int i=0;i<heights.size();i++){
            while(st.empty()==false and heights[st.top()]>heights[i]){
                int t= st.top();
                st.pop();
                curr=heights[t]*(st.empty()?i:(i-st.top()-1));
                ans=max(ans, curr);
            }   
            st.push(i);
        }
        int n=heights.size();
        while(st.empty()==false){
            int t= st.top();
            st.pop();
            curr= heights[t]*(st.empty()?n:(n-st.top()-1));
            ans= max(ans, curr);
        }
        return ans;
    }
};