class Solution {
private:
void dfs(vector<vector<int>>& A, vector<vector<bool>>& visited, queue<pair<int, int>>& q,
int i, int j, vector<vector<int>>& dirs) {
if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || visited[i][j] || A[i][j]
== 0)

return;
visited[i][j] = true;
q.push({i, j});
for (auto& dir : dirs)
dfs(A, visited, q, i + dir[0], j + dir[1], dirs);
}
public:
int shortestBridge(vector<vector<int>>& A) {
int m = A.size(), n = A[0].size();
vector<vector<bool>> visited(m, vector<bool>(n, false));
vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int>> q;
bool found = false;
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
if (A[i][j] == 1) {
dfs(A, visited, q, i, j, dirs);
found = true;
break;
}
}
if (found) break;
}
int step = 0;
while (!q.empty()) {
int size = q.size();
while (size-- > 0) {
auto cur = q.front();
q.pop();
for (auto& dir : dirs) {
int i = cur.first + dir[0];

int j = cur.second + dir[1];
if (i >= 0 && j >= 0 && i < m && j < n && !visited[i][j]) {
if (A[i][j] == 1) {
return step;
}
q.push({i, j});
visited[i][j] = true;
}
}
}
step++;
}
return -1;
}
};