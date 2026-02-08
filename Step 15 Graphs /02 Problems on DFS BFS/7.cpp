// LC130 Surrounded Regions
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
  void solve(vector<vector<char>> &board) {
    int n = board.size();
    int m = board[0].size();

    // {row, col}
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // border cells
        if ((j == 0 || i == 0 || j == m - 1 || i == n - 1) && board[i][j] == 'O') {
          // mark them as "N" -> can't be surrounded
          board[i][j] = 'N';
          q.push({i, j});
        }
      }
    }

    int dRow[] = {-1, 1, 0, 0};
    int dCol[] = {0, 0, -1, 1};
    // now run a bfs on the Os that touch the edge
    while (!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();

      // visit it's neighbours
      for (int i = 0; i < 4; i++) {
        int nr = r + dRow[i];
        int nc = c + dCol[i];

        if (nr >= 0 && nc >= 0 && nr < n && nc < m && board[nr][nc] == 'O') {
          // mark it and push it into the grid
          board[nr][nc] = 'N';
          q.push({nr, nc});
        }
      }
    }

    // now just mark all the 'O's as X and the Ns as Os
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'N')
          board[i][j] = 'O';
        else if (board[i][j] == 'O')
          board[i][j] = 'X';
      }
    }
  }
};
