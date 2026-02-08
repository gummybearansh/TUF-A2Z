// LC1020 Number of Enclaves
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numEnclaves(vector<vector<int>> &grid) {
    // bfs on the land cells along the boundary
    // mark them as -1, all the cells that u can reach from the boundary cells will also be marked as -1
    int n = grid.size();
    int m = grid[0].size();

    // {row, col}
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1) {
          grid[i][j] = -1;
          q.push({i, j});
        }
      }
    }

    int dRow[] = {-1, 0, 0, 1};
    int dCol[] = {0, -1, 1, 0};
    while (!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();

      // visit it's neighbours that are also land
      for (int i = 0; i < 4; i++) {
        int nr = r + dRow[i];
        int nc = c + dCol[i];

        // if this is a valid land cell -> then we mark it as well
        if (nr >= 0 && nc >= 0 && nr < n - 1 && nc < m - 1 && grid[nr][nc] == 1) {
          grid[nr][nc] = -1;
          q.push({nr, nc});
        }
      }
    }

    // now the remaining land cells are good
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1)
          count++;
      }
    }

    return count;
  }
};
