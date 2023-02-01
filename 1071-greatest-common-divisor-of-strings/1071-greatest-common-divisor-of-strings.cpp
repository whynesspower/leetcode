class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string s = str1;
        if(str1.size()>str2.size()){
            s= str2;
        }
        string ans="";
        int n = min(str1.size(), str2.size());
        for(int i=0;i<n;i++){
            string temp=s.substr(0, i+1);
            int len=temp.size();
            int a= str1.size()/len;
            int b= str2.size()/len;
            // string aa=temp, bb=temp;
            string aa="",bb="";
            for(int j=0;j<a;j++){
                aa+=temp;
            }
            for(int j=0;j<b;j++){
                bb+=temp;
            }
            if(aa==str1 and bb==str2){
                ans=max(ans, temp);
            }
        }
        return ans;
    }
};