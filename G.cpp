#include <iostream>

#include <vector>

void ReadGraph(std::vector<std::vector<bool>>& graph, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      bool temp;
      std::cin >> temp;
      graph[i].push_back(temp);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<std::vector<bool>> graph(n);
  ReadGraph(graph, n);
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        graph[i][j] = graph[i][j] or (graph[i][k] and graph[k][j]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << graph[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
