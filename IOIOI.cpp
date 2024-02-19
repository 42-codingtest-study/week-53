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
  string s;
  int N, M, answer = 0;
  cin >> N >> M >> s;
  for (int i = 0; i < M; i++) {
    if (s[i] == 'I') {
      int cnt = 0;
      while (s[i + 1] == 'O' && s[i + 2] == 'I') {
        i += 2, cnt++;
        if (cnt == N) cnt--, answer++;
      }
    }
  }
  cout << answer;
}
