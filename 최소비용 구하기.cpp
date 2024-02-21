#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

int main() {
  fast;
  int N, M, a, b, c, s, e;
  cin >> N >> M;
  vector<vector<int>> cost(N + 1, vector<int>(N + 1, 1e9));
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    cost[a][b] = min(cost[a][b], c);
  }
  cin >> s >> e;
  for (int i = 1; i <= N; i++) cost[i][i] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> dist(N + 1, 1e9);
  dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    int curDist = pq.top().first, cur = pq.top().second;
    pq.pop();
    if (dist[cur] < curDist) continue;
    for (int i = 1; i <= N; i++) {
      if (cost[cur][i] != 1e9 && dist[i] > dist[cur] + cost[cur][i]) {
        dist[i] = dist[cur] + cost[cur][i];
        pq.push({dist[i], i});
      }
    }
  }
  cout << dist[e];
}
