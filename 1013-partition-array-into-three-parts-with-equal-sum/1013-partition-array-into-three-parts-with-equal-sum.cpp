class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n=arr.size();
        int l=1, r=n-2;
        int lsum=arr[0];
        int rsum=arr[n-1];
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        // if(sum==0) return true;
        if(sum%3!=0) return false;
        int target=sum/3;
        int currsum=0;
        int i=0;
        int cnt=0;
        for(;i<n;i++){
            currsum+=arr[i];
            if(currsum==target){
                currsum=0;
                cnt++;
            }
        }
        if(cnt>=3) return true;
        return false;
        // while(l<=r){
        //     if(lsum==rsum and rsum==sum){
        //         return true;
        //     }
        //     if(lsum<rsum){
        //         lsum+=arr[l];
        //         sum-=arr[l];
        //         l++;
        //     }
        //     else{
        //         rsum+=arr[r];
        //         sum-=arr[r];
        //         r--;
        //     }
        // }
        // return false;
    }
};