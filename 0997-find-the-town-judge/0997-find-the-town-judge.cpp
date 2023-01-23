class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int>cntBe;
        unordered_map<int,int>Be;
        for(int i=0;i<trust.size();i++){
            int a = trust[i][0];
            int b = trust[i][1];
            cntBe.insert(a);
            Be[b]++;
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(cntBe.find(i)==cntBe.end() and Be[i]==(n-1)){
                ans=i;
                break;
            }
        }
        return ans;
    }
};