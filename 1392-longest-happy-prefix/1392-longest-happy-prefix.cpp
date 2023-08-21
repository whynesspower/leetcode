class Solution {
public:
    vector<int>lps;
    void createLps(int n, string &s){
        int i=1,j=0;
        while(i<n){
            if(s[i]==s[j]){
                lps[i]=j+1;
                j++;
                i++;
            }
            else{
                if(j==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    j=lps[j-1];
                }
            }
        }
    }
    string longestPrefix(string s) {
        int n=s.size();
        lps.resize(n,0);
        createLps(n,s);
        int ansLength=lps[n-1];
        cout<<lps[n-1]<<endl;
        string ans=s.substr(n-ansLength);
        return ans;
    }
};