
// Leetcode 547. Number of provinces
#include <iostream>

using namespace std;

// basically need to find number of components in adjacency matrix
// Leetcode Solution:
class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    // basically need to find number of connected components in an adjacency matrix
    // run bfs on each node, number of traversals required to reach each node is the number of provincesj
    int ans = 0, n = isConnected.size();
    // n because 0 based indexing
    vector<bool> vis(n, 0);
    // i represents node -> going over all nodes
    for (int i = 0; i < n; i++) {
      // if the current node has not been visited
      if (!vis[i]) {
        // then visit it and run bfs
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        // since needed to traverse to reach this, this is a new province
        ans++;
        // standard bfs
        while (!q.empty()) {
          int node = q.front();
          q.pop();
          for (int j = 0; j < n; j++) {
            // add the neighbours into the queue that have not been visited, j is the neghbour node
            if (isConnected[node][j] == 1 && vis[j] == 0) {
              q.push(j);
              vis[j] = 1;
            }
          }
        }
      }
    }

    return ans;
  }
};

int findComponents(vector<vector<int>> &adj_mat) {
  int ans = 0;
  // need to run bfs on each node as long as it's not visited. number of traversals = components
  int n = adj_mat.size();
  // n because nodes are 0 indexed

  vector<int> visited(n, 0);
  // say we start at 0
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      q.push(i);
      visited[i] = 1;
      ans++;
      while (!q.empty()) {
        // standard bfs traversal -> add the neighbours of current element to the queue and mark them visited
        int node = q.front();
        q.pop();
        for (int j = 0; j < n; j++) {
          if (adj_mat[node][j] == 1 && visited[j] == 0) {
            q.push(j);
            visited[j] = 1;
          }
        }
      }
    }
  }

  return ans;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj_mat(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> adj_mat[i][j];
    }
  }
  // for (auto r : adj_mat) {
  //   for (auto c : r) {
  //     cout << c << ' ';
  //   }
  //   cout << '\n';
  // }

  cout << findComponents(adj_mat);
}
