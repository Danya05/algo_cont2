#include <iostream>

#include <vector>

#include <set>

void ReadGraph(std::vector<std::vector<std::pair<int, int>>>& graph, size_t m) {
  for (size_t i = 0; i < m; ++i) {
    int x, y, z;
    std::cin >> x >> y >> z;
    graph[x + 1].emplace_back(y + 1, z);
    graph[y + 1].emplace_back(x + 1, z);
  }
}

void Dijkstra(std::vector<std::vector<std::pair<int, int>>>& graph, int start,
              std::vector<int>& dist) {
  dist[start + 1] = 0;
  std::set<std::pair<int, int>> queue;
  queue.insert({0, start + 1});
  while (!queue.empty()) {
    auto[top, v] = *queue.begin();
    queue.erase(queue.begin());

    for (auto u : graph[v]) {
      int u_val = u.first;
      int w = u.second;
      if (dist[u_val] > dist[v] + w) {
        if (queue.find({dist[u_val], u_val}) != queue.end()) {
          queue.erase({dist[u_val], u_val});
        }
        dist[u_val] = dist[v] + w;
        queue.insert({dist[u_val], u_val});
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int num_of_graphs;
  std::cin >> num_of_graphs;
  for (int z = 0; z < num_of_graphs; ++z) {
    int n, m;
    std::cin >> n >> m;
    int start;
    std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
    std::vector<int> dist(n + 1, 2009000999);
    ReadGraph(graph, m);
    std::cin >> start;
    Dijkstra(graph, start, dist);
    for (int i = 1; i < n + 1; ++i) {
      std::cout << dist[i] << " ";
    }
    std::cout << std::endl;
  }
}
