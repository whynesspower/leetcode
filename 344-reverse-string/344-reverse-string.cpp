class Solution {
public:
    void reverseString(vector<char>& s) {
        int n= s.size();
        int m = n/2;
        for(int i=0;i<m;i++){
            char temp= s[i];
            s[i]=s[n-i-1];
            s[n-1-i]=temp;
        }
    }
};