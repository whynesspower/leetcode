class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        // priority_queue<int,vector<int>,greater<int>>pq;
        priority_queue<int>pq;
        
        for(int i=0;i<s.size();i++){
            pq.push(s[i]);
        }
        while(!pq.empty()){
            int a= pq.top();
            pq.pop();
            if(pq.empty()) return a;
            int b= pq.top();
            pq.pop();
            if(a==b){
                continue;
            }
            else{
                pq.push(abs(a-b));
            }
        }
        return 0;
    }
};