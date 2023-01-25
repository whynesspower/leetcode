//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    bool isvalid(string s1)
    {

       if(s1.size()>3||s1.size()==0) return false;

       if(s1.size()>1 && s1[0]=='0') return false;

       // using stoi to convert string to integer 

       if(s1.size() && stoi(s1)>255) return false;



       return true;
    }
  
    void dfs(vector<string>&ans, string &s, int dots, string tilNow, int i){
        if(dots==3){
            string temp=s.substr(i);
            if(isvalid(temp)){
                // tilNow+=temp;
                ans.push_back(tilNow+temp);
            }
        }
        for(int j=i;j<s.size();j++){
            string t= s.substr(i, j-i+1);
            if(isvalid(t)){
                tilNow+=s[j];
                tilNow+='.';
                dfs(ans, s, dots+1, tilNow, j+1);
                tilNow.pop_back();
            }
        }
        return;
    }
  
    vector<string> genIp(string &s) {
        // Your code here
        vector<string>ans;
        if(s.size()<4){
            ans.push_back("-1");
            return ans;
            
        }
        dfs(ans, s, 0, "", 0);
        if(ans.size()==0){
            ans.push_back("-1");
            return ans;
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends