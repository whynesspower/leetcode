class Solution {
public:
    bool isRobotBounded(string ins) {
        string dir="north";
        int x=0, y=0;
        if(ins.length()==0) return false;
        
        for(auto &t:ins){
            if(t=='G'){
                if(dir=="north"){
                    y++;
                }
                else if(dir=="south"){
                    y--;
                }
                else if(dir=="east"){
                    x++;
                }
                else{
                    x--;
                }
            }
            else if(t=='L'){
                if(dir=="north"){
                    dir= "west";
                }
                else if(dir=="east")
                    dir="north";
                else if(dir=="south")
                    dir="east";
                else{
                    dir="south";
                }
            }
            else if(t=='R'){
                if(dir=="north"){
                    dir= "east";
                }
                else if(dir=="east")
                    dir="south";
                else if(dir=="south")
                    dir="west";
                else{
                    dir="north";
                }
            }
            
        }
        
        
        if(x==0 and y ==0) return true;
        if(dir =="north") return false;
        return true;
    }
};