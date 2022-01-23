class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q{{1,2,3,4,5,6,7,8,9}};
        vector<int> ans;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(i>=low and i<=high){
                ans.push_back(i);
            }
            if(i> high){
                break;
            }
            int lastdigit=i%10;
            if(lastdigit<9){
                q.push(i*10 + lastdigit+1);
            }
            
        }
        return ans;
    }
};