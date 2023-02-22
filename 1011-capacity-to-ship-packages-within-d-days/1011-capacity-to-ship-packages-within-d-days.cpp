class Solution {
public:
    bool solve(vector<int>& w, int d, int mid){
        int need=1;
        int currwt=0;
        for(int i=0;i<w.size();i++){
            currwt+=w[i];
            if(currwt>mid){
                currwt=w[i];
                need++;
            }
        }
        if(need<=d) return true;
        return false;
    }
    
    
    int shipWithinDays(vector<int>& w, int d) {
        int r= 1e8;
        int l = *max_element(w.begin(), w.end());
        // cout<<l<<endl;
        // sort(w.begin(), w.end());
        while(l<=r){
            int mid= (r+l)/2;
            // mid is the weight capacity
            // solve return true if its possible to 
            // ship "mid" capacity of weights within d days 
            if(solve(w,d,mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};