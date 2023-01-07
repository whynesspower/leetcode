class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int is_possible=0;
        int n=gas.size();
        vector<int>ans(n, -1);
        int currfuel=0;
        for(int i=0;i<n;i++){
            is_possible+=gas[i]-cost[i];
            currfuel+=gas[i];
            currfuel-=cost[i];
            if(currfuel<0){
                start=i+1;
                currfuel=0;
            }
        }
        return (is_possible<0)? -1:start;
    }
}; 