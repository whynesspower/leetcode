class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int sz = cost.size();
        vector<int> minCostToPaintWall(sz + 1, 5e8+1);
        //painting zero walls will cost us zero money
        minCostToPaintWall[0] = 0;
        //for each wall you will consider whether paid painter can take up this wall or not and carry out the effect of this decision on the remaining number of walls
        for(int wallIndx = 0; wallIndx < sz;  wallIndx++){
            //take contribution of your choice of either selecting or not selecting current wall for paid painter
            for(int remWalls = sz; remWalls > 0; remWalls--){
                minCostToPaintWall[remWalls] = min(
                        //skip the current wall to be assigned to paid painter
                        minCostToPaintWall[remWalls],
                        //assign current wall to paid painter
                        //time[wallIndx] --> no of wall painted by free painter in the time which 
                        //paid painter paints 1 wall
                        minCostToPaintWall[max(remWalls - time[wallIndx] - 1, 0)] + cost[wallIndx]

                );
            }
        }
        return  minCostToPaintWall[sz];
    }
};