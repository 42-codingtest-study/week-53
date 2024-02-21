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

ll sum(ll n, ll d) {
  if (n == 1) return 1;
  return pow(n, d) + sum(n - 1, d);
}

int main() {
  fast;
  ll N;
  cin >> N;
  cout << sum(N, 1) << "\n"
       << static_cast<int>(pow(sum(N, 1), 2)) << "\n"
       << sum(N, 3);
}
