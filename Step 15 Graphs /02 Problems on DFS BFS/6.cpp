// LC 542: 0/1 Matrix
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
  // i need to find the distance of the nearest 0 for each cell
  // instead -> if i think in opposite

  // every 0 starts spreading simultaneously
  // if it reaches a cell that is 1, that means i have found the shortest parth to that cell. So i'll update that cell's val to this distance
  int n = mat.size();    // n rows
  int m = mat[0].size(); // m cols

  // fill them all with -1 initially
  vector<vector<int>> ans(n, vector<int>(m, -1));
  // {{row, col}, dist}
  queue<pair<pair<int, int>, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 0) {
        // this cell is already at 0
        ans[i][j] = 0;
        // but also add it to our bfs queue
        q.push({{i, j}, 0});
      }
    }
  }

  // now i'll go over my queue, and reach all 1s and update their distance
  int drow[] = {-1, 0, 0, 1};
  int dcol[] = {0, -1, 1, 0};
  while (!q.empty()) {
    int r = q.front().first.first;
    int c = q.front().first.second;
    int d = q.front().second;
    q.pop();

    // now visit it's neighbours
    for (int i = 0; i < 4; i++) {
      int nr = r + drow[i];
      int nc = c + dcol[i];

      // if ans[nr][nc] == -1 => tht cell has not been visited before
      if (nr >= 0 && nc >= 0 && nr < n && nc < m && ans[nr][nc] == -1) {
        // since it's the he first time i reach this cell this is the shortest path to this cell.
        ans[nr][nc] = d + 1;
        // it'll take +1 distance to reach this guy
        // add it to the queue, so i can reach his neighbours as well
        q.push({{nr, nc}, d + 1});
      }
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> v(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  vector<vector<int>> ans = updateMatrix(v);

  for (auto r : ans) {
    for (auto c : r) {
      cout << c << ' ';
    }
    cout << '\n';
  }
}
