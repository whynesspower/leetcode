class Solution {
public:
    bool solve(int reqScore, int l, int r,vector<int>& nums, int k){
        int i=k, j=k;
        int n=nums.size();
        int currMin=nums[k];
        int currScore=nums[k];
        while(i>=0 and j<n){
            if(currScore>=reqScore) return true;
            if(i-1>=0 and j+1<n){
                if(nums[i-1]>nums[j+1]){
                    i--;
                    currMin=min(currMin, nums[i]);
                    currScore=currMin*(j-i+1);
                }
                else if(nums[j+1]> nums[i-1]){
                    j++;
                    currMin=min(currMin, nums[j]);
                    currScore=currMin*(j-i+1);
                }
                else{
                    i--;
                    j++;
                    currMin=min(currMin, nums[i]);
                    currScore=currMin*(j-i+1);
                }
            }
            else if(i-1>=0){
                i--;
                currMin=min(currMin, nums[i]);
                currScore=currMin*(j-i+1);
            }
            else if(j+1<n){
                j++;
                currMin=min(currMin, nums[j]);
                currScore=currMin*(j-i+1);
            }
            else{
                return false;
            }
        }
        return (currScore<reqScore)?false:true;
    }
    int maximumScore(vector<int>& nums, int k) {
        int l=0, r=INT_MAX;
        while(l<=r){
            // mid is the maximum score possible
            int mid=(l+(r-l)/2);
            
            if(solve(mid, l, r, nums,k)){
                cout<<mid<<"  l is  "<<l<<endl;
                l=mid+1;
            }
            else{
                cout<<mid<<" r is  "<<r<<endl;
                r=mid-1;
            }
        }
        return l-1;
    }
};