class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int maxHours) {

        int low=1, high=INT_MIN;
        for(auto x:piles){
            high= max(high, x);
        }
        
        static const auto fastIO = []() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        return 0;    }();
        int ans;
        int currSpeed=0;
        
        while(low<=high){    
            currSpeed= low+ (high-low)/2;
            int currHours=0;
            for(int i=0;i<piles.size();i++){
                currHours+=( ceil(1.0*piles[i]/currSpeed) );
            }
            if(currHours <= maxHours){
                ans=currSpeed;
                high=currSpeed-1;
            }          
            else{
                low=currSpeed+1;
            }
        }
        
        return ans;
    }
};