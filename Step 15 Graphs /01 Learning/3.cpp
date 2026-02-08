// DFS
#include <iostream>

using namespace std;

vector<vector<int>> graph_input_list(int n, int m) {
  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  return graph;
}

void dfs_stack(vector<vector<int>> &adj_list, int n, int start) {
  vector<int> vis(n + 1, 0);
  vis[start] = 1;
  stack<int> s;
  s.push(start);
  while (!s.empty()) {
    // go to it's dpeth
    int node = s.top();
    cout << node << ' ';
    s.pop();
    for (auto neighbour : adj_list[node]) {
      if (!vis[neighbour]) {
        s.push(neighbour);
        vis[neighbour] = 1;
      }
    }
  }
  cout << '\n';
}

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj_list) {
  // mark this as visited, print it. and run dfs on it's neighbours
  visited[node] = true;
  cout << node << ' ';

  for (auto neighbour : adj_list[node]) {
    if (!visited[neighbour]) {
      dfs(neighbour, visited, adj_list);
    }
  }
}

void print_dfs(vector<vector<int>> &adj_list, int n, int start) {
  vector<bool> visited(n + 1);
  visited[start] = true;

  dfs(start, visited, adj_list);
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adjacency_list = graph_input_list(n, m);

  dfs_stack(adjacency_list, n, 1);
  print_dfs(adjacency_list, n, 1);

  // for (auto r : adjacency_list) {
  //   for (auto c : r) {
  //     cout << c << ' ';
  //   }
  //   cout << '\n';
  // }
}
