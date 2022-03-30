class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m==0 or n==0) return false;
        int start= 0, end = m*n-1;
        
        while(start<=end){
            int mid= start+ (end-start)/2;
            int temp= matrix[mid/n][mid%n];
            if(target==temp){
                return true;
            }
            else if(target < temp){
                end = mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return false;
    }
};