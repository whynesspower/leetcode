class Solution {
public:
    
    
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        return a.first + a.second> b.first+ b.second;
    }
    
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    
        int aliceScore=0, bobScore=0;
        int n=aliceValues.size();
        
        vector<pair<int,int>>timepass(n);
        
        for(int i=0;i<n;i++){
            timepass.push_back({aliceValues[i],bobValues[i]});
        }
        
        sort(timepass.begin(), timepass.end(), comp);
        
        int i=0;        
        while(i<n){
            if(i%2==0){
                aliceScore+=timepass[i].first;
            }
            else{
                bobScore+=timepass[i].second;
            }
            i++;
        }
            
        if(bobScore<aliceScore){
            return 1;
        }
        else if(bobScore==aliceScore){
            return 0;
        }
        else{
            return -1;
        }
    }
};