// practice revision
#include <iostream>
using namespace std;

void print_adjacency_list(vector<vector<int>> &v) {
  for (auto connected_to : v) {
    for (auto node : connected_to) {
      cout << node << ' ';
    }
    cout << '\n';
  }
}

vector<vector<int>> graph_input_list(int n, int m) {
  // take edge input
  vector<vector<int>> v(n + 1);
  for (int i = 0; i < m; i++) {
    int node_1, node_2;
    cin >> node_1 >> node_2;

    // representing the edge between node 1 and node 2 as adjacency list (most common)

    v[node_1].push_back(node_2);
    v[node_2].push_back(node_1);
  }

  return v;
}

void bfs(vector<vector<int>> &graph, int n, int m, int start) {
  // what does bfs do?
  // it visits the start node, and then visits the neighbour nodes,
  // uses a queue, also a visited array to not revisit again and again
  vector<bool> vis(n + 1, false);
  queue<int> q;
  q.push(start);
  vis[start] = true;
  // the bfs will run till the queue is empty, when you're pushing 'neighbours' into the queue -> mark them as visited, because when u remove then and visit their neighbours u won't have to
  while (!q.empty()) {
    // visit the neighbours:
    int node = q.front();
    cout << node << ' ';
    q.pop();
    for (int neighbour : graph[node]) {
      if (!vis[neighbour]) {
        vis[neighbour] = true;
        q.push(neighbour);
      }
    }
  }
}

vector<vector<int>> graph_input_matrix(int n, int m) {
  // need adjacency list -> representaiton of each edge
  vector<vector<int>> grid(n + 1, vector<int>(n + 1));
  for (int i = 0; i < m; i++) {
    int n1, n2;
    cin >> n1 >> n2;
    grid[n1][n2] = 1;
    grid[n2][n1] = 1;
  }
  return grid;
}

void print_adjacency_matrix(vector<vector<int>> &graph) {
  for (int i = 0; i < graph.size(); i++) {
    for (int j = 0; j < graph.size(); j++) {
      cout << graph[i][j] << ' ';
    }
    cout << '\n';
  }
}

int orangesRotting(vector<vector<int>> &grid) {
  // need to give the minimum number of minutes till all oranges have been rotten, or -1 if not possible to rot the oranges

  // the way nodes are pushed -> {{x, y}, time}
  queue<pair<pair<int, int>, int>> q;
  // don't need a visited, since we'll just mark the node as 2, and we're only technically visiting nodes that are 1 that are reachable by 2

  // need initial nodes that are 2
  int fresh_oranges = 0;
  int n = grid.size(), m = grid[0].size();
  for (int i = 0; i < n; i++) {   // n
    for (int j = 0; j < m; j++) { // n*m
      if (grid[i][j] == 2) {
        // these initial nodes are already 2 at time = 0;
        q.push({{i, j}, 0});
      } else if (grid[i][j] == 1) {
        fresh_oranges++;
      }
    }
  }

  int ans = 0;
  int rotted_oranges = 0;
  int drow[] = {-1, 0, 1, 0};
  int dcol[] = {0, 1, 0, -1};
  while (!q.empty()) { // n*m
    // all the details of the node being popped
    int r = q.front().first.first;
    int c = q.front().first.second;
    int time = q.front().second;
    q.pop();

    ans = max(ans, time);

    for (int i = 0; i < 4; i++) { // 1
      int nr = r + drow[i];
      int nc = c + dcol[i];
      if (nr < n && nr >= 0 && nc >= 0 && nc < m) {
        // if this a valid cell, these are the new cols
        // and this is a fresh orange
        if (grid[nr][nc] == 1) {
          rotted_oranges++;
          grid[nr][nc] = 2;
          // add this new node to visit later
          q.push({{nr, nc}, time + 1});
        }
      }
    }
  }
  // even smarter -> if i have the count of oranges i rotted, i can just subtract from the initial fresh oranges and i'll know if i was able to rot all of them

  if (rotted_oranges == fresh_oranges)
    return ans;
  else
    return -1;
  // // confirm that all oranges are now rotten
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     if (grid[i][j] == 1)
  //       return -1;
  //   }
  // }
}

int main() {
  // n = nodes, m = edges
  int n, m;
  cin >> n >> m;

  // vector<vector<int>> graph = graph_input_list(n, m);
  // vector<vector<int>> grid = graph_input_matrix(n, m);
  // print_adjacency_list(graph);
  // print_adjacency_matrix(grid);
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j]; // Enter 0, 1, or 2
    }
  }

  // bfs(graph, n, m, 2);
  int days = orangesRotting(grid);
  cout << days << '\n';
}
