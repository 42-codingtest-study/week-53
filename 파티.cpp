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

int main() {
  fast;
  int N, M, X, A, B, T;
  cin >> N >> M >> X;
  vector<vector<int>> dist(N + 1, vector<int>(N + 1, 1e9));
  for (int i = 1; i <= N; i++) dist[i][i] = 0;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> T;
    dist[A][B] = T;
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  int max_time = 0;
  for (int i = 1; i <= N; i++)
    max_time = max(max_time, dist[i][X] + dist[X][i]);
  cout << max_time;
}
