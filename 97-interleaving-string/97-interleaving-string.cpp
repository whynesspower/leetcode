class Solution {
private:
    unordered_map<string, bool>mp;
    
public:
    bool check(string s1, string s2, string s3, int len1, int len2, int len3, int p1, int p2, int p3){
        if(p3==len3){
            if(p2==len2 and p1==len1){
                return true;
            }
            else return false;
        }
        string key= to_string(p1)+"*"+to_string(p2)+"*"+ to_string(p3);
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        if(p1==len1){
            return mp[key]= (s2[p2]==s3[p3])?check(s1, s2,s3,len1, len2, len3,p1, p2+1, p3+1):false;
        }
        if(p2==len2){
            return mp[key]= (s1[p1]==s3[p3])?check(s1, s2,s3,len1, len2, len3,p1+1, p2, p3+1):false;
        }
        bool one=false, two=false;
        if(s1[p1]==s3[p3]){
            one=check(s1, s2,s3,len1, len2, len3,p1+1, p2, p3+1);
        }
        if(s2[p2]==s3[p3]){
            two=check(s1, s2,s3,len1, len2, len3,p1, p2+1, p3+1);
        }
        return mp[key]=one or two;
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.size();
        int len2=s2.size();
        int len3=s3.size();
        if(len3!=len2+len1){
            return false;
        }
        return check(s1, s2, s3, len1,len2, len3, 0,0,0);
    }
};