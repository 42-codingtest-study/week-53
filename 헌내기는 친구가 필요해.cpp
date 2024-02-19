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

int N, M, x, y, answer = 0;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
string s;

int main() {
  fast;
  cin >> N >> M;
  vector<vector<string>> graph(N, vector<string>(M, "0"));
  vector<vector<int>> visited(N, vector<int>(M, 0));
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < M; j++) {
      if (s[j] == 'I') x = i, y = j;
      graph[i][j] = s[j];
    }
  }
  queue<pair<int, int>> q;
  q.push({x, y});
  visited[x][y] = 1;
  while (!q.empty()) {
    int a = q.front().first, b = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = a + dx[i], ny = b + dy[i];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] ||
          graph[nx][ny] == "X")
        continue;
      if (graph[nx][ny] == "P") answer++;
      visited[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
  if (answer)
    cout << answer;
  else
    cout << "TT";
}
