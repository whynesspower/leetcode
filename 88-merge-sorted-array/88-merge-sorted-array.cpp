class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        int a =0, b=0;
        while(a<m and b<n){
            if(nums1[a]< nums2[b]){
                ans.push_back(nums1[a]);
                a++;
            }
            else if(nums1[a] > nums2[b]){
                ans.push_back(nums2[b]);
                b++;
            }
            else{
                ans.push_back(nums1[a]);
                ans.push_back(nums2[b]);
                a++;
                b++;
            }
        }
        while(a<m){
            
                ans.push_back(nums1[a++]);
        }
        while(b<n){
            
                ans.push_back(nums2[b++]);
        }
        
        for(int i=0;i<(m+n); i++){
            nums1[i]=ans[i];
        }
        
    }
};