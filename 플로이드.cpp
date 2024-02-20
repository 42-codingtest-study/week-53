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
#define MAX 10000001

int main() {
  fast;
  int n, m, a, b, c;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1, vector<int>(n + 1, MAX));
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    graph[a][b] = min(graph[a][b], c);
  }
  for (int i = 1; i <= n; i++) graph[i][i] = 0;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (graph[i][j] >= MAX)
        cout << 0 << ' ';
      else
        cout << graph[i][j] << ' ';
    }
    cout << '\n';
  }
}
