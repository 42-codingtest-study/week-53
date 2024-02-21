#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

#define INF numeric_limits<int>::max()

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> dist(graph.size(), INF);
  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int curDist = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (dist[cur] < curDist) continue;

    for (auto& edge : graph[cur]) {
      int next = edge.first;
      int weight = edge.second;
      if (curDist + weight < dist[next]) {
        dist[next] = curDist + weight;
        pq.push({dist[next], next});
      }
    }
  }

  return dist;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int V, E, K;
  cin >> V >> E >> K;
  vector<vector<pair<int, int>>> graph(V + 1);
  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});  // 간선 정보 저장
  }

  vector<int> dist = dijkstra(graph, K);
  for (int i = 1; i <= V; i++) {
    if (dist[i] == INF)
      cout << "INF" << '\n';
    else
      cout << dist[i] << '\n';
  }
}
