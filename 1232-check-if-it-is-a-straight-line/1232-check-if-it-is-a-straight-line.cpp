class Solution {
public:
    bool check(int x1, int y1, double m ,vector<vector<int>>& c, int i){
        int x2=c[i][0];
        int y2=c[i][1];
        // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<m<<endl;
        double y=m;
        double a=x2-x1;
        y*=a;
        y+=y1;
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<m<<" "<<y<<endl;
        if(y==y2){
            return true;
        }
        return false;
    }
    
    
    bool checkStraightLine(vector<vector<int>>& c) {
        if(c.size()<=2) return true;
        int x1=c[0][0];
        int y1=c[0][1];
        int x2=c[1][0];
        int y2=c[1][1];
        double m= (double)(y2-y1);
        if((x2-x1)==0){
            // m is infinity 
            for(int i=2;i<c.size();i++){
                if(c[0][0]!=c[i][0]){
                    return false;
                }
            }
            return true;
        }
        m/=(double)(x2-x1);
        
        // y=mx+y1-mx1;
        // y=m(x-x1)+y1
        // equaltion of line :
            // y-y1=m(x-x1)
        for(int i=2;i<c.size();i++){
            if(check(x1,y1, m, c, i)==false){
                return false;
            }
        }
        return true;
    }
};