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

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int main() {
  fast;
  int N, answer[2] = {0, 0};
  string s;
  vector<string> graph;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    graph.push_back(s);
  }
  vector<vector<int>> visited(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j] == 0) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        answer[0]++;
        while (!q.empty()) {
          int nx = q.front().first, ny = q.front().second;
          q.pop();
          for (int k = 0; k < 4; k++) {
            int x = nx + dx[k], y = ny + dy[k];
            if (x < 0 || x >= N || y < 0 || y >= N || visited[x][y] ||
                graph[x][y] != graph[nx][ny])
              continue;
            visited[x][y] = 1;
            q.push({x, y});
          }
        }
      }
    }
  }
  visited.assign(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j] == 0) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        answer[1]++;
        while (!q.empty()) {
          int nx = q.front().first, ny = q.front().second;
          q.pop();
          for (int k = 0; k < 4; k++) {
            int x = nx + dx[k], y = ny + dy[k];
            if (x < 0 || x >= N || y < 0 || y >= N || visited[x][y] ||
                (graph[x][y] == 'B' && graph[nx][ny] != 'B') ||
                (graph[x][y] != 'B' && graph[nx][ny] == 'B'))
              continue;
            visited[x][y] = 1;
            q.push({x, y});
          }
        }
      }
    }
  }
  cout << answer[0] << ' ' << answer[1];
}
