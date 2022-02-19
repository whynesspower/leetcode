class Solution {
public:
    
    int minimumDeviation(vector<int>& nums) {
        int mini=INT_MAX; 
        priority_queue<int>pq;
        
        for(int i=0;i<nums.size();i++){
             
             if(nums[i]%2!=0){
                 nums[i]*=2;
             }
        }
        
        for(int i=0;i<nums.size();i++){
            mini=min(mini, nums[i]);
            pq.push(nums[i]);
        }
        
        int ans=INT_MAX;
        
        while(pq.top()%2==0){
            int tep=pq.top();
            pq.pop();
            ans=min(ans, tep-mini);
            mini=min(mini, tep/2);
            tep/=2;
            pq.push(tep);
        }
        
        return min(ans, pq.top()-mini);
    }
};