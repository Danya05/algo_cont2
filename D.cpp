#include <iostream>

#include <vector>

class Edge {
 public:
  int u, v, w;
};

void ReadGraph(std::vector<Edge>& graph, size_t m) {
  for (size_t i = 0; i < m; ++i) {
    int x, y, z;
    std::cin >> x >> y >> z;
    graph.push_back(Edge{x - 1, y - 1, z});
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<Edge> graph;
  std::vector<int> dist(n, 30000);
  ReadGraph(graph, m);
  dist[0] = 0;
  for (int k = 0; k < n - 1; ++k) {
    for (int j = 0; j < m; ++j) {
      if (dist[graph[j].u] < 30000) {
        dist[graph[j].v] =
            std::min(dist[graph[j].v], dist[graph[j].u] + graph[j].w);
      }
    }
  }
  for (auto i : dist) {
    std::cout << i << " ";
  }
}
