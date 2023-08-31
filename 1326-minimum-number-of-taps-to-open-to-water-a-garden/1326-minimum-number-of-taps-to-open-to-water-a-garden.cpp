class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>arr(n+1, 0);
        for(int i=0;i<n+1;i++){
            int left= max(0,i- ranges[i]);
            arr[left]=max(arr[left], i+ranges[i]);
        }
        int end=0, ans=0, reach_so_far=0;
        for(int i=0;i<=n;i++){
            if(i>end){
                if(reach_so_far<=end)return -1;
                end=reach_so_far;
                ans++;
            }
            reach_so_far=max(reach_so_far, arr[i]);
        }
        return ans +(end<n);
    }
};