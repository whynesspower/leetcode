class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
                vector<int>minkk;
        vector<int>maxkk;
        int n=nums.size();
        vector<int>redundant;
        
        for(int i=0;i<n;i++){
            if(nums[i]==minK) minkk.push_back(i);
            if(nums[i]==maxK) maxkk.push_back(i);
            if(nums[i]>maxK or nums[i]<minK) redundant.push_back(i);
        }
        
        long long ans=0;
        for(int i=0;i<n;i++){
            auto a= lower_bound(minkk.begin(), minkk.end(), i);
            auto b= lower_bound(maxkk.begin(), maxkk.end(), i);
            auto c= lower_bound(redundant.begin(), redundant.end(), i);    
            if(a==minkk.end() or b==maxkk.end()){
                continue;
            }
            int aa= *a;
            int bb= *b;
            int cc;
            if(c==redundant.end()){
                 cc=n;
            }
            else{
                 cc= *c;
            }
            int temp=cc-max(aa,bb);
            if(temp<0) continue;
            ans+=temp;
        }
        
        return ans;
    }
};