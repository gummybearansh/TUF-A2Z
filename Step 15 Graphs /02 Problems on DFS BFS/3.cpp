// LC. 733
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
  int n = image.size();
  int m = image[0].size();
  // i need to start at the {sr, sc}, change it's color to "color"
  // then i'll just do a bfs to each neighbouring node, and if it's color is also 'color' then i'll change that too
  // and i'll keep a track of visited nodes as well
  // ok not just any neighbour - i need to make sure the neighbour also has the same color as the initial starting node

  // initial config
  // {row, col}
  queue<pair<int, int>> q;
  vector<vector<int>> vis(n, vector<int>(m, 0));
  vis[sr][sc] = 1;
  q.push({sr, sc});
  int initialColor = image[sr][sc];
  image[sr][sc] = color;

  int drow[] = {-1, 0, 1, 0};
  int dcol[] = {0, -1, 0, 1};
  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    // it's a given, only then i'll reach this node
    image[r][c] = color;
    vis[r][c] = 1;

    // now i need to add all it's valid neighbours
    for (int i = 0; i < 4; i++) {
      int nr = r + drow[i];
      int nc = c + dcol[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != 1 && image[nr][nc] == initialColor) {
        q.push({nr, nc});
      }
    }
  }

  return image;
}

int main() {
  int n, m, sr, sc, color;
  cin >> n >> m >> sr >> sc >> color;
  vector<vector<int>> image(n, vector<int>(m));
  for (auto &r : image) {
    for (auto &c : r) {
      cin >> c;
    }
  }

  vector<vector<int>> updatedImage = floodFill(image, sr, sc, color);

  for (auto r : updatedImage) {
    for (auto c : r) {
      cout << c << ' ';
    }
    cout << '\n';
  }
}
