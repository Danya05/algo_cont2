#include <iostream>

#include <vector>

#include <set>

void ReadGraph(std::vector<std::vector<std::pair<int64_t, int64_t>>>& graph,
               size_t m) {
  for (size_t i = 0; i < m; ++i) {
    int64_t x, y, z;
    std::cin >> x >> y >> z;
    graph[x].emplace_back(y, z);
    graph[y].emplace_back(x, z);
  }
}

void Dijkstra(std::vector<std::vector<std::pair<int64_t, int64_t>>>& graph,
              int64_t start, std::vector<int64_t>& dist) {
  dist[start] = 0;
  std::set<std::pair<int64_t, int64_t>> queue;
  queue.insert({0, start});
  while (!queue.empty()) {
    auto[top, v] = *queue.begin();
    queue.erase(queue.begin());

    for (auto u : graph[v]) {
      int64_t u_val = u.first;
      int64_t w = u.second;
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
  int64_t n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int64_t> vec_of_black;
  for (int64_t i = 0; i < k; ++i) {
    int64_t temp;
    std::cin >> temp;
    vec_of_black.push_back(temp);
  }
  int64_t start, end;
  std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(n + 1);
  std::vector<int64_t> dist(n + 1, INT64_MAX);
  ReadGraph(graph, m);
  std::cin >> start >> end;
  Dijkstra(graph, end, dist);
  bool flag = false;
  if (dist[start] == INT64_MAX) {
    std::cout << -1;
  } else {
    for (int64_t i : vec_of_black) {
      if (dist[i] <= dist[start]) {
        flag = true;
        std::cout << -1;
        break;
      }
    }
    if (!flag) {
      std::cout << dist[start];
    }
  }
}
