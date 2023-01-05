//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    bool allign(vector<int>&v1, vector<int>&v2){
        for(int i=0;i<26;i++){
            if(v1[i]<v2[i] and v2[i]!=0) return false;
        }
        return true;
    }

    string smallestWindow (string s, string p)
    {
        int n=s.size();
        vector<int>v1(26,0);
        vector<int>v2(26, 0);
        vector<int>dp(n+1);
        for(int i=0;i<p.size();i++){
            v2[p[i]-'a']++;
        }
        unordered_map<char, vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        int j=0;
        while((allign(v1, v2)==false) and (j<n)){
            v1[s[j]-'a']++;
            j++;
        }
        if(j==n){
            return "-1";
        }
        j--;
        dp[0]=j;
        
        // cout<<dp[0]<<" ";
        for(int i=1;i<n;i++){
            v1[s[i-1]-'a']-=1;
            if(allign(v1,v2)){
                dp[i]=dp[i-1];
            }
            else{
                vector<int>temp=mp[s[i-1]];
                auto jj=upper_bound(temp.begin(), temp.end(), j);
                int a= jj-temp.begin();
                if(a>=temp.size()){
                    dp[i]=-1;
                    break;
                }
                else{
                    int b= temp[a];
                    dp[i]=b;
                    for(int k=j+1;k<=b;k++)
                    {v1[s[k]-'a']++;}
                    j=b;
                }
            }
            //  cout<<dp[i]<<" ";
        }
        int diff=INT_MAX;
        string res;
        pair<int, int>anss;
        for(int i=0;i<n;i++){
            int aa= dp[i];
            if(aa<0) break;
            if((aa-i+1)<diff){
                diff=aa-i+1;
                res=s.substr(i, aa-i+1);
            }
            // cout<<dp[i]<<" ";
        }
        return res;
        
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends