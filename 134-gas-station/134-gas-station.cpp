class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int surplus(0), deficient(0), start(0);
        for(int i=0;i<gas.size();i++){
            surplus= surplus+gas[i]-cost[i];
            if(surplus<0){
                start=i+1;
                deficient+=surplus;
                surplus=0;
            }
        }
        return surplus+deficient>=0?start:-1;
    }
};