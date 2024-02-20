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
  ll A, B;
  cin >> A >> B;
  queue<pair<ll, int>> q;
  q.push({A, 0});
  while (!q.empty()) {
    ll cur = q.front().first, cnt = q.front().second;
    q.pop();
    if (cur == B) {
      cout << cnt + 1;
      return 0;
    }
    ll next[2] = {cur * 2, cur * 10 + 1};
    for (int i = 0; i < 2; i++)
      if (next[i] <= B) q.push({next[i], cnt + 1});
  }
  cout << -1;
}
