// BFS (breadth first search) (level wise traversal)
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> graph_list_input(int n, int m) {
  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  return graph;
}

// gets nodes, adjacency_list, starting node
void BFS(int n, vector<vector<int>> &adjacency_list, int start) {
  // initial config -> queue, visited array
  queue<int> q;
  q.push(start);
  vector<bool> visited(n + 1, false);
  visited[start] = true;

  while (!q.empty()) {
    // print the node (BFS traversal)
    int node = q.front();
    cout << node << ' ';
    q.pop();

    // now visit all members of this node
    for (int neighbour : adjacency_list[node]) {
      // if the node is not visited, add it to the queue, and mark it visited
      if (!visited[neighbour]) {
        q.push(neighbour);
        visited[neighbour] = true;
      }
    }
  }
}

int main() {
  // nodes, edges
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adjacency_list = graph_list_input(n, m);
  // for (auto r : adjacency_list) {
  //   for (auto c : r) {
  //     cout << c << ' ';
  //   }
  //   cout << '\n';
  // }
  BFS(n, adjacency_list, 1);
}
