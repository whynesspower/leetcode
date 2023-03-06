class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int m=arr[arr.size()-1];
        int j=0;
        int n=arr.size();
        for(int i=1;i<=m and j<n;i++){
            
            if(j<n and arr[j]!=i){
                k--;
            }
            else{
                j++;
            }
            if(k==0) return i;
            cout<<i<<" ";
        }
        return m+k;
    }
};