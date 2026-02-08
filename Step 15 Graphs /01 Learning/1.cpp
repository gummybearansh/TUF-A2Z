// Ways to take graph as input
#include <iostream>

using namespace std;

vector<vector<int>> graph_matrix_input(int n, int m) {
  // adjacency matrix size (n+1)x(n+1) => 1 based indexing of nodes, initialy all 0
  vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    // meaning edge from u->v as well as v->u (undirected)
    graph[u][v] = 1;
    graph[v][u] = 1;
  }

  return graph;
}

vector<vector<int>> graph_list_input(int n, int m){
  // list size => n+1 (1 based node indexing)
  vector<vector<int>> graph (n+1);
  for (int i = 0; i < m; i++){
    // edge from u -> v
    int u, v; cin >> u >> v;
    // adding u as neighbour to v, and v as neighbour to u (undirected);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  return graph;
}

int main() {
  // n = nodes, m = edges
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adjacency_list = graph_list_input(n, m);

  // vector<vector<int>> adjacency_matrix = graph_matrix_input(n, m);
  for (auto r : adjacency_list) {
    for (auto c : r) {
      cout << c << ' ';
    }
    cout << '\n';
  }
}
