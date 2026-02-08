// LC1765
#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
  // start at the 0s, push them in queue.
  // move bfs outwards, each cell marked as +1
  int n = isWater.size();
  int m = isWater[0].size();

  // {{r, c}, height}
  queue<pair<pair<int, int>, int>> q;
  vector<vector<int>> res(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (isWater[i][j] == 1) {
        res[i][j] = 0;
        q.push({{i, j}, 0});
      }
    }
  }

  int dRow[] = {-1, 0, 0, 1};
  int dCol[] = {0, -1, 1, 0};
  while (!q.empty()) {
    int r = q.front().first.first;
    int c = q.front().first.second;
    int height = q.front().second;
    q.pop();

    // now visit all neighbours and add them to queue with height+1
    for (int i = 0; i < 4; i++) {
      int nr = r + dRow[i];
      int nc = c + dCol[i];

      if (nr >= 0 && nc >= 0 && nr < n && nc < m && res[nr][nc] == -1) {
        res[nr][nc] = height + 1;
        q.push({{nr, nc}, height + 1});
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));

  for (auto &r : grid) {
    for (auto &c : r) {
      cin >> c;
    }
  }

  vector<vector<int>> res = highestPeak(grid);
  for (auto r : res) {
    for (auto c : r) {
      cout << c << ' ';
    }
    cout << '\n';
  }
}
