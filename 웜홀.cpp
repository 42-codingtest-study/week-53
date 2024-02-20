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
  int N, M, W, TC, S, E, T;
  cin >> TC;
  while (TC--) {
    cin >> N >> M >> W;
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, 1e9));
    for (int i = 1; i <= N; i++) dist[i][i] = 0;
    for (int i = 0; i < M; i++) {
      cin >> S >> E >> T;
      dist[S][E] = min(dist[S][E], T), dist[E][S] = min(dist[E][S], T);
    }
    for (int i = 0; i < W; i++) {
      cin >> S >> E >> T;
      dist[S][E] = min(dist[S][E], -T);
    }
    vector<int> upper(N + 1, 1e9);
    upper[1] = 0;
    bool updated = false;
    for (int i = 1; i <= N; i++) {
      updated = false;
      for (int j = 1; j <= N; j++) {
        for (int k = 1; k <= N; k++) {
          if (dist[j][k] != 1e9 && upper[k] > upper[j] + dist[j][k]) {
            upper[k] = upper[j] + dist[j][k];
            updated = true;
          }
        }
      }
      if (!updated) break;
    }
    if (updated)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
