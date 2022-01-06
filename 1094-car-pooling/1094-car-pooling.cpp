class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int arr[1001];
        memset(arr, 0, sizeof(arr));
        for(int i=0;i<trips.size();i++){
            int a = trips[i][1];
            int b = trips[i][2];
            for(int j=a ; j<b; j++){
                arr[j]+=trips[i][0];            
            }
        }
        for(int i=0;i<=1000;i++){
            if(arr[i]>capacity){
                return false;
            }
        }
        
        return true;
        
    }
};