class Solution {
public:
    vector<vector<int>>pascal;

    vector<int> getRow(int rowIndex) {
        pascal.push_back({1});
        pascal.push_back({1,1});
        
        for(int i=2;i<=33;i++){
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<i;j++){
                temp.push_back(pascal[i-1][j]+ pascal[i-1][j-1]);
            }
            temp.push_back(1);
            pascal.push_back(temp);
        }    
        return pascal[rowIndex];
    }
};