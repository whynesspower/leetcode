class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string ans="";
        while(str){
            string word;
            str>>word;
            reverse(word.begin(), word.end());
            ans+=word;
            ans+=" ";
        }
        int n=ans.size();
        return ans.substr(0, n-2);
    }
};