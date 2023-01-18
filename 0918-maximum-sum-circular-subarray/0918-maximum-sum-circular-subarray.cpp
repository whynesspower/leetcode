class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        
        int sum=a[0];
        int curr_max = a[0], max_so_far = a[0], curr_min = a[0], min_so_far = a[0];
        for(int i=1;i<a.size();i++){
            sum+=a[i];
            curr_max=max(curr_max+a[i], a[i]);
            max_so_far=max(max_so_far, curr_max);
            curr_min=min(curr_min+a[i], a[i]);
            min_so_far=min(min_so_far, curr_min);
        }
        if(sum==min_so_far) return max_so_far;
        return max(max_so_far, sum-min_so_far);
    }
};