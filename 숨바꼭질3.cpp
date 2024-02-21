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
  int N, K;
  cin >> N >> K;
  vector<int> visited(100001, 2147483647);
  queue<int> q;
  q.push(N);
  visited[N] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == K) {
      cout << visited[cur] << '\n';
      break;
    }
    if (cur - 1 >= 0 && visited[cur - 1] > visited[cur] + 1) {
      visited[cur - 1] = visited[cur] + 1;
      q.push(cur - 1);
    }
    if (cur + 1 <= 100000 && visited[cur + 1] > visited[cur] + 1) {
      visited[cur + 1] = visited[cur] + 1;
      q.push(cur + 1);
    }
    if (cur * 2 <= 100000 && visited[cur * 2] > visited[cur]) {
      visited[cur * 2] = visited[cur];
      q.push(cur * 2);
    }
  }
}
