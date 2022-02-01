class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int op=0;//overall profit
        int lst=INT_MAX;//least number so far
        int ptoday=0; //profit if sold today
        
        for(int i=0;i<prices.size();i++){
            lst= min(lst, prices[i]);
            ptoday=prices[i]-lst;
            op=max(op, ptoday);
        }
        
        return op;
        
    }
};