class Solution {
public:
    string simplifyPath(string path) {
        stack<string>ans;
        
        for(int i=0;i<path.size();i++){
            if(path[i]=='/')continue;
            string temp;
                
            while(i < path.size() and path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp==".")continue;
            else if(temp==".."){
                if(!ans.empty()){
                    ans.pop();
                }
            }
            else{
                ans.push(temp);
            }
        }
        
        string anss="";
        while(ans.empty()==false){
            anss = "/"+ans.top() + anss;
            ans.pop();
        }
        
        if(anss.size() == 0)
            return "/";
        
        return anss;
    }
};