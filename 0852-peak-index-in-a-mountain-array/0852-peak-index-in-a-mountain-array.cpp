class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=arr.size()-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            cout<<mid<<endl;
            if((r-l+1)<3){
                cout<<"mid"<<mid<<" "<<l<<" "<<r;
                return mid;
            } 
            if(arr[mid-1]>=arr[mid] and arr[mid]>= arr[mid+1]){
                r=mid;
            }
            else if(arr[mid-1]<=arr[mid] and arr[mid]<= arr[mid+1]){
                l=mid;
            }
            else{
                return mid;
            }
        }
        cout<<l<<" ";
        return l;
    }
};