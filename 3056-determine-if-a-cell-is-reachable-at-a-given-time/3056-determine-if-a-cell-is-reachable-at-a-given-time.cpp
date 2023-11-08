class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx and sy==fy){
            if(t!=1)return true;
            return false;
        } 
        int distX=abs(fx-sx);
        int distY=abs(fy-sy);
        int minDist=min(distX, distY);
        int maxDist=max(distX, distY);
        int minReq=minDist;
        minReq+= (maxDist-minDist);
        return t>=minReq;
        // if(t>=minDist) return true;
        // return false;
    }
};