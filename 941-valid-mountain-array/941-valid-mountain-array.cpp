class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        int increasing=1;
        if(n<3){
            return false;
        }
        
        bool flag=0;
        for(int i=1;i<n;i++){
            
            if(arr[i]>arr[i-1]){
                flag=1;
            } 
        }
        if(flag==0) return false;
        
        
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]) return false;
            if(arr[i]>arr[i-1] and increasing){
                continue;
            }
            else if(arr[i]<arr[i-1]){
                increasing=0;
                continue;
            }
            else if(arr[i]>arr[i-1] and increasing==0 ){
                return false;
            }
        }
        if(increasing) return false;
        return true;
    }
};