class Solution {
public:
    int l=0;

    int calcualteInt(string s, int n){
        int left=l;
        while(s[l]!='['){
            // right++;
            l++;
        }
        int right=l-1;
        string num= s.substr(left, right-left+1);
        int Num=stol(num);
        l++;
        return Num;
    }
    string dfs(string &s, int n){
        string currStr="";
        while(l< n){
            cout<<s[l]<<" ";
            if(s[l]>='0' and s[l]<='9'){
                int cnt=calcualteInt(s, n);
                string New=dfs(s, n);
                while(cnt--){
                    currStr+=New;
                }
            }
            else if(s[l]==']'){
                l++;
                return currStr;
            }
            else{
                currStr+=s[l];
                l++;
            }
        }
        return currStr;
    }
    string decodeString(string s) {
        int n=s.size();
        return dfs(s, n);
    }
};