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
  int N, x, ans = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x;
    ans += x;
  }
  cout << (ans > 0 ? "Right" : (ans < 0 ? "Left" : "Stay"));
}
