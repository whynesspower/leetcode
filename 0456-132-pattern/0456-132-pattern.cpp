class Solution {
public:
    bool find132pattern(vector<int>& nums) {


        stack<int>st;
        int n=nums.size();
        vector<int>smallestSoFar(n,0), nextSmaller(n, 0);
        smallestSoFar[0]=nums[0];
       
        // [3,5,0,3,4]
        // [0,0,0,3,4]
        // [3,3,0,0,0]

        for(int i=1;i<n;i++){
            smallestSoFar[i]=min(smallestSoFar[i-1], nums[i]);
        }
        

        for(int i=n-1;i>=0;i--){
            if(nums[i]>smallestSoFar[i]){
                while(st.empty()==false and st.top()<=smallestSoFar[i]){
                    st.pop();
                }
                if(!st.empty() and st.top()<nums[i]){
                    return true;
                }

            }
            st.push(nums[i]);
        }

       
        return false;

    }
};