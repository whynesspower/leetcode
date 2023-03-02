class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0, j=0;
        string s="";
        int n=chars.size();
        int len=i;
        while(i<n){
            s+=chars[i];
            while(j<n and chars[i]==chars[j]){
                j++;
            }
            if(j-i==1){
                i=j;
                continue;
            }
            else{
                int a = j-i;
                s+=to_string(a);
            }
            // if(i<n-1) chars[i+1]= char(j-i + '0'); 
            i=j;
        }
        for(int i=0;i<s.size();i++){
            chars[i]=s[i];
        }
        return s.size();
    }
};