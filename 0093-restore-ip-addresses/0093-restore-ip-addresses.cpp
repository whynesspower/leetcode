class Solution {
public:
    bool isValid(string s1)
    {

       if(s1.size()>3||s1.size()==0) return false;

       if(s1.size()>1 && s1[0]=='0') return false;

       // using stoi to convert string to integer 

       if(s1.size() && stoi(s1)>255) return false;



       return true;
    }
    void dfs(string &s, vector<string>&ans, int i, int points, string temp ){
        if(points==3){
            if(isValid(s.substr(i))){
                ans.push_back(temp+ s.substr(i));
            }
        }
        for(int j=i;j<s.size();j++){
            if(isValid(s.substr(i, j-i+1))){
                temp.push_back(s[j]);
                temp.push_back('.');
                dfs(s, ans, j+1, points+1, temp);
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        vector<int>points;
        // points.push_back(1);
        int n=s.size();
        if(n<4) return ans;
        // for(int i=1;i<=5;i+=2){
        //     points.push_back(i);
        // }
        // string temp="";
        dfs(s, ans,0, 0, "");
        return ans;
    }
};