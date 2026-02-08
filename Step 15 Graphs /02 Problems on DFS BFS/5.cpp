// Cycle in undirected graph (DFS)
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj_list) {
  vis[node] = 1;
  for (auto neighbour : adj_list[node]) {
    // if i have not visited this neighbour, visit it and do dfs
    if (!vis[neighbour]) {
      if (dfs(neighbour, node, vis, adj_list)) {
        // incase i find a cycle from my neigbour -> then i'll also return true
        return true;
      }
    }
    // i have a neighbour that's visited
    else if (neighbour != parent) {
      // that means someone else has already visited this, and there's a cycle in the graph
      return true;
    }
  }
  // if after going through the dfs of all nodes, i still don't find a cycle, i return false
  return false;
}

bool has_cycle_naive(int src, vector<int> &vis, vector<vector<int>> &adj_list) {
  // if i start at the src node, and i can reach it again by dfs, then there exists a cycle in the graph
  // but i also need to track the parent - yes
  vis[src] = 1;
  // {node, parent}
  stack<pair<int, int>> sk;
  sk.push({src, -1});

  while (!sk.empty()) {
    int node = sk.top().first;
    int parent = sk.top().second;
    sk.pop();

    for (auto neighbour : adj_list[node]) {
      if (!vis[neighbour]) {
        vis[neighbour] = 1;
        sk.push({neighbour, node});
      } else if (parent != neighbour) {
        return true;
      }
    }
  }
  return false;
}

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

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj_list = graph_input_list(n, m);

  vector<int> vis(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      if (dfs(i, -1, vis, adj_list)) {
        cout << "Has Cycle\n";
        return 0;
      }
    }
  }
  cout << "No cycle";
}
