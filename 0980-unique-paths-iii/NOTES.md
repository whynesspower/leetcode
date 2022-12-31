```
class Solution {
private:
int ans=0;
int zeroCnt=1;
public:
void dfs(vector<vector<int>>&g, int x, int y, int count){
if(x<0 or x>=g.size() or y<0 or y>=g[0].size() or g[x][y]==-1)return;
if(g[x][y]==2){
if(zeroCnt==count){
ans++;
}
return;
}
g[x][y]=-1;
dfs(g, x+1, y, count++);
dfs(g, x-1, y, count++);
dfs(g, x, y+1, count++);
dfs(g, x, y-1, count++);
g[x][y]=0;
}
int uniquePathsIII(vector<vector<int>>& g) {
int start_x, start_y;
for(int i=0;i<g.size();i++){
for(int j=0;j<g[0].size();j++){
if(g[i][j]==1){
start_x=i;
start_y=j;
}
else if(g[i][j]==0){
zeroCnt++;
}
}
}
dfs(g, start_x, start_y, 0);
return ans;
}
};
```