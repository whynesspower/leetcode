class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        
        
        while(columnNumber){    
            columnNumber--;
            int c=columnNumber%26;
            ans.push_back(c+'A');
            columnNumber/=26;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};