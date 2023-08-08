class Solution {
public:
    int indexOfTarget(vector<int>nums, int target, int l ,int r){
        // return index of the target element present 
        // in the array nums beteen l and r
        // cout<<target<<" "<<l<<" "<<r<<endl;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                // cout<<mid<<" ";
                return mid;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int pointOfRotation=-1;
        int n=nums.size();
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid+1<n and nums[mid+1]<nums[mid]){
                pointOfRotation=mid;
                break;
            }
            else if(mid-1>=0 and nums[mid-1]>nums[mid]){
                pointOfRotation=mid-1;
                break;
            }
            else{
                if(nums[mid]>nums[r]){
                    l=mid+1;
                }
                else if(nums[mid]<nums[l]){
                    r=mid-1;
                }
                else{
                    break;
                }
            }
        }
        l=0, r=nums.size()-1;
        cout<<pointOfRotation<<" ";
        if(pointOfRotation==-1){
           int a= indexOfTarget(nums, target, l, r);
            if(a!=-1) return a;
        }
        else{
            // 0 to ptOfRotation
            // ptofRotation +1 to last
            int a= indexOfTarget(nums, target, l, pointOfRotation );
            if(a!=-1) return a;
            int b= indexOfTarget(nums, target, pointOfRotation +1, r);
            if(b!=-1) return b;
        }
        return -1;
    }
};