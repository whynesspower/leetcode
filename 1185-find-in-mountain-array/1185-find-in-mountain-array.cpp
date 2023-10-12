/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findMiddleIndex( MountainArray &mountainArr, int l, int r, int n){
        if(l>r) return -1;
        int mid= (l+r)/2;
        int middleEle=mountainArr.get(mid);
        int prevEle=-1, nextEle=INT_MAX;
        if(mid>0) prevEle=mountainArr.get(mid-1);
        if(mid<n-1) nextEle=mountainArr.get(mid+1);
        if(prevEle<middleEle && middleEle>nextEle){
            return mid;
        }
        else if(prevEle< middleEle && nextEle>middleEle){
            return findMiddleIndex(mountainArr, mid+1, r, n);
        }
        else if(prevEle > middleEle && nextEle < middleEle){
            return findMiddleIndex(mountainArr, l, mid-1, n);
        }
        return mid;
    }
    
    // this function finds if target exist between l and r
    // if not then it return -1
    int binarySearch(MountainArray &arr, int l, int r, int n, int t){
        if(l>r) return -1;
        int mid= (l+r)/2;
        int middleEle=arr.get(mid);
        if(middleEle==t) return mid;
        else if(middleEle>t){
            return binarySearch(arr,l, mid-1,n , t );
        }
        else{
            return binarySearch(arr,mid+1, r, n, t);
        }
    }
    int binarySearch2(MountainArray &arr, int l, int r, int n, int t){
        if(l>r) return -1;
        int mid= (l+r)/2;
        int middleEle=arr.get(mid);
        if(middleEle==t) return mid;
        else if(middleEle>t){
            return binarySearch(arr,mid+1, r, n, t);
        }
        else{
            return binarySearch(arr,l, mid-1,n , t );
        }
    }


    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int mntIndx= findMiddleIndex(mountainArr, 0, n-1, n);
        // increasing array
        int ansleft=binarySearch(mountainArr,0, mntIndx, n, target);
        
        // decreasing array
        int ansRight=binarySearch2(mountainArr, mntIndx+1, n-1, n, target);
        cout<<mntIndx<<" "<<ansleft<<" "<<ansRight<<endl;
        if(ansleft!=-1){
            return ansleft;
        }
        if(ansRight!=-1){
            return ansRight;
        }
        return -1;
    }
};