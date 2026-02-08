// Connected Components
// find how many connected components does the graph have
#include <iostream>
#include <queue>

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

void bfs(int n, int m, vector<vector<int>> &adjacency_list, vector<int> &visited, int start) {
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int neighbour : adjacency_list[node]) {
      if (!visited[neighbour]) {
        visited[neighbour] = true;
        q.push(neighbour);
      }
    }
  }
}

int connected_components(int n, int m, vector<vector<int>> &adjacency_list) {
  int ans = 0;
  // essentially need to do a bfs on each node that is not visited.
  // number of traversals needed = number of components
  vector<int> visited(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (visited[i])
      continue;
    bfs(n, m, adjacency_list, visited, i);
    ans++;
  }
  return ans;
}

int main() {
  // nodes, edges
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adjacency_list = graph_input_list(n, m);
  // for (auto r : adjacency_list) {
  //   for (auto c : r) {
  //     cout << c << ' ';
  //   }
  //   cout << '\n';
  // }
  cout << connected_components(n, m, adjacency_list);
}
