class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>st;
        int left=INT_MAX, right=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!st.empty() and nums[st.back()] > nums[i]){
                left=min(left, st.back());
                st.pop_back();
            }
            st.push_back(i);
        }
        st.clear();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums[st.back()] <  nums[i]){
                right=max(right,st.back() );
                st.pop_back();
            }
            st.push_back(i);
        }
        return left==INT_MAX?0:(right-left+1);
    }
    
};