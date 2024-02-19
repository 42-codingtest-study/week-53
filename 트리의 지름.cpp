#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

void dfs(int curr, vector<vector<pair<int, int>>>& graph,
         vector<int>& visited) {
  for (auto& edge : graph[curr]) {
    int next = edge.first;
    int weight = edge.second;
    if (visited[next] == -1) {
      visited[next] = visited[curr] + weight;
      dfs(next, graph, visited);
    }
  }
}

int main() {
  fast;
  int n, a, b, c;
  cin >> n;
  vector<vector<pair<int, int>>> graph(n + 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    graph[a].push_back({b, c}), graph[b].push_back({a, c});
  }
  int r1 = 1, answer = 0;
  vector<int> visited(n + 1, -1);
  visited[1] = 0;
  dfs(1, graph, visited);
  for (int i = 1; i <= n; i++)
    if (visited[i] > answer) answer = visited[i], r1 = i;
  visited.assign(n + 1, -1);
  visited[r1] = 0;
  dfs(r1, graph, visited);
  answer = 0;
  for (int i = 1; i <= n; i++) answer = max(answer, visited[i]);
  cout << answer << '\n';
}
