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
#define MBTI_CNT 16

int getDist(string a, string b, string c) {
  int dist = 0;
  for (int i = 0; i < a.size(); i++) {
    dist += (a[i] != b[i]) + (b[i] != c[i]) + (c[i] != a[i]);
  }
  return dist;
}

int solve(int N, vector<string> mbtis) {
  if (N > MBTI_CNT * 2) return 0;

  int answer = 1e9;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        answer = min(answer, getDist(mbtis[i], mbtis[j], mbtis[k]));
      }
    }
  }
  return answer;
}

int main() {
  fast;
  int T, N;
  cin >> T;
  while (T--) {
    cin >> N;
    vector<string> mbtis(N);
    for (int i = 0; i < N; i++) {
      cin >> mbtis[i];
    }
    cout << solve(N, mbtis) << '\n';
  }
}
