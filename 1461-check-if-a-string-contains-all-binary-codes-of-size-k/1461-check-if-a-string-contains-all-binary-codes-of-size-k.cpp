class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int left=0, right=k-1;
        while(right<s.size()){
            string temp= s.substr(left, k);
            st.insert(temp);
            left++;
            right++;
        }
        int temp2=1<<k;
        if(st.size()==temp2){
            return true;
        }
        else return false;
    }
};