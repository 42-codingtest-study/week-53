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
  int x0, N;
  cin >> x0 >> N;
  for (int i = 0; i < N; i++) {
    x0 = x0 % 2 ? (2 * x0) ^ 6 : (x0 / 2) ^ 6;
  }
  cout << x0;
}
