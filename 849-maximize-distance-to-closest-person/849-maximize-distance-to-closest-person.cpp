class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    
        int prev=-1;
        int ans=0;
        
        for(int i=0;i<seats.size();i++){
        
            if(seats[i]==1){
                if(prev==-1){
                    ans=i;
                }
                else{
                    ans=max( (i-prev)/2, ans);
                }
    
                prev=i;
            }
            
        }
        int n=seats.size()-1;
        ans= max(ans, n- prev);

        return ans;
    }
};