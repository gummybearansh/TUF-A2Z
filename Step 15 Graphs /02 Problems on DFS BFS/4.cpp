// detect a cycle in an undirected graph (bfs)
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph_input_list(int n, int m) {
  vector<vector<int>> adj_list(n + 1);
  for (int i = 0; i < m; i++) {
    int n1, n2;
    cin >> n1 >> n2;

    adj_list[n1].push_back(n2);
    adj_list[n2].push_back(n1);
  }

  return adj_list;
}

bool has_cycle(int src, vector<int> &vis, vector<vector<int>> &adj_list) {
  // i need to run a bfs from src
  vis[src] = 1;
  // stores -> {node, parent} -> parent to track where i came from
  queue<pair<int, int>> q;
  q.push({src, -1});

  while (!q.empty()) {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();

    // visit all the neighbours of this node (standard bfs)
    for (auto neighbour : adj_list[node]) {
      if (!vis[neighbour]) {
        vis[neighbour] = 1;
        // push the neighbour with the current node as the parent
        q.push({neighbour, node});
      }
      // now what if the neighbour of this node has been marked visited
      // this means that the node must be the parent of this node
      // if it's not the parent - then there's  cycle in the graph
      else if (neighbour != parent) {
        // yes this has a cycle
        return true;
      }
    }
  }

  // if no cycle was found
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj_list = graph_input_list(n, m);

  // keep track of visited (incase graph has components)
  vector<int> vis(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      if (has_cycle(i, vis, adj_list)) {
        cout << "Has cycle";
        return 0;
      }
    }
  }

  cout << "No cycle";

  // for (auto r : adj_list) {
  //   for (auto c : r) {
  //     cout << c << ' ';
  //   }
  //   cout << "\n";
  // }
}
