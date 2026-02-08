// LC 994. Rotten Oranges
// multi source BFS problem
#include <iostream>

using namespace std;

int orangesRotting(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();

  // no need for visited -> the grid itslef can store the state
  // queue has -> {i, j}, time
  queue<pair<pair<int, int>, int>> q;
  // initial set up
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 2) {
        q.push({{i, j}, 0});
      }
    }
  }

  // now start bfs
  // delta row and col for 4 directions (to find the neighbours)
  int drow[] = {-1, 0, 1, 0};
  int dcol[] = {0, 1, 0, -1};
  int time = 0, mxTime = 0;
  while (!q.empty()) {
    int r = q.front().first.first;
    int c = q.front().first.second;
    int t = q.front().second;
    q.pop();

    mxTime = max(mxTime, t);
    // visit all it's neighbours
    for (int i = 0; i < 4; i++) {
      int nrow = r + drow[i];
      int ncol = c + dcol[i];

      // check bounds and if it's a fresh orange and it has not been visited before
      if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
        grid[nrow][ncol] = 2;
        q.push({{nrow, ncol}, t + 1});
      }
    }
  }

  // confirm if no fresh oranges left
  // can also count the fresh oranges in initial traversal and compare with total rotten
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1) {
        return -1;
      }
    }
  }
  return mxTime;
}

int main() {
  int m, n;
  cin >> m >> n; // dimenstions of grid

  vector<vector<int>> grid(m, vector<int>(n));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  // minumum number of days till all oranges are rotten, -1 otherwise
  cout << orangesRotting(grid);

  // for (auto r : grid) {
  //   for (auto c : r) {
  //     cout << c << ' ';
  //   }
  //   cout << '\n';
  // }
}
