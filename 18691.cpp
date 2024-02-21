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
  int T, G, C, E;
  cin >> T;
  while (T--) {
    cin >> G >> C >> E;
    int RC = E - C;
    int RK = (G == 1 ? RC : G == 2 ? 3 * RC : 5 * RC);
    cout << (RK <= 0 ? 0 : RK) << "\n";
  }
}
