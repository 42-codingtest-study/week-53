#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define ll long long

// 주어진 4가지 연산을 수행하는 함수들
int calD(int a) { return (a * 2) % 10000; }
int calS(int a) { return a == 0 ? 9999 : a - 1; }
int calL(int a) { return (a % 1000) * 10 + a / 1000; }
int calR(int a) { return (a % 10) * 1000 + a / 10; }

int main() {
  fast;
  int T, A, B;
  cin >> T;
  while (T--) {
    cin >> A >> B;
    vector<bool> visited(10000, false);
    queue<pair<int, string>> q;
    q.push({A, ""});
    visited[A] = true;

    while (!q.empty()) {
      int curr = q.front().first;
      string op = q.front().second;
      q.pop();

      if (curr == B) {
        cout << op << "\n";
        break;
      }
      vector<pair<int, char>> nextStates = {{calD(curr), 'D'},
                                            {calS(curr), 'S'},
                                            {calL(curr), 'L'},
                                            {calR(curr), 'R'}};
      for (auto& ns : nextStates) {
        if (!visited[ns.first]) {
          visited[ns.first] = true;
          q.push({ns.first, op + ns.second});
        }
      }
    }
  }
  return 0;
}
