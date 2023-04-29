class UnionFind{
// private: 

public: 
    vector<int>parent;
    vector<int>rank;
    UnionFind(int n){
        // parent.resize(n, -1);
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        rank.resize(n, 0);
    }
    void unite(int a, int b){
        int pa= find(a);
        int pb= find(b);
        if(pa==pb) return;
        if(rank[pa]> rank[pb]){
            parent[pb]=pa;
        }
        else if(rank[pa]< rank[pb]){
            parent[pa]=pb;
        }
        else{
            parent[pa]=pb;
            rank[pb]++;
        }
    }
    int find(int a){
        if(parent[a]!=a){
            parent[a]=find(parent[a]);
        }
        return parent[a];
    }
    

};

class Solution {
public:
    bool static compare(const vector<int>&a, const vector<int>&b){
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        UnionFind uf(n);
        vector<bool>ans(queries.size(), false);
        
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        
        sort(edgeList.begin(), edgeList.end(), compare);
        sort(queries.begin(), queries.end(), compare);

        int j=0;
        for(int i=0;i<queries.size();i++){
            for(;j<edgeList.size() and (edgeList[j][2]< queries[i][2]);j++){
                uf.unite(edgeList[j][0], edgeList[j][1]);
            }
            ans[queries[i][3]]= uf.find(queries[i][0]) == uf.find(queries[i][1])? 1:0;
        }
        return ans;
    }
};