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
  int N;
  vector<vector<int>> adj;
  cin >> N;
  adj.resize(N + 1, vector<int>(N + 1, 0));
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) cin >> adj[i][j];
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        if (adj[i][k] && adj[k][j]) adj[i][j] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) cout << adj[i][j] << ' ';
    cout << '\n';
  }
}
