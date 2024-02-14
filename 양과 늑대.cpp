#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> info;
vector<vector<int>> edges, graph(17);
vector<bool> visited(17, false);
int maxSheep = 0;

void dfs(int node, int sheep, int wolf, vector<int>& available) {
  if (info[node] == 0)
    sheep++;
  else
    wolf++;
  if (wolf >= sheep) return;
  maxSheep = max(maxSheep, sheep);
  vector<int> nextAvailable = available;
  nextAvailable.erase(remove(nextAvailable.begin(), nextAvailable.end(), node),
                      nextAvailable.end());
  for (int next : graph[node])
    if (!visited[next]) nextAvailable.push_back(next);
  visited[node] = true;
  for (int next : nextAvailable) dfs(next, sheep, wolf, nextAvailable);
  visited[node] = false;
}

int solution(vector<int> a, vector<vector<int>> e) {
  info = a, edges = e;
  for (auto& edge : edges) {
    int u = edge[0], v = edge[1];
    graph[u].push_back(v), graph[v].push_back(u);
  }
  vector<int> available;
  for (int child : graph[0]) available.push_back(child);
  dfs(0, 0, 0, available);
  return maxSheep;
}
