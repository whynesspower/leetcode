class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans=0, mask=0;
        for(int i=31;i>=0;i--){
            unordered_set<int>st;
            mask= mask|(1<<i);
            for(auto x:nums){
                st.insert(x&mask);
            }
            
            int temp = ans|(1<<i);
            for(auto x:st){
                if(st.find(temp^x)!=st.end()){
                    ans=temp;
                    break;
                }
            }
        }
        return ans;
    }
};