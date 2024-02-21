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
  int n, x, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ans += (x % 2 == 0 ? 1 : -1);
  }
  cout << (ans > 0 ? "Happy" : "Sad");
}
