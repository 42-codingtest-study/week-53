#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)

int main() {
  fast;
  float W, H;
  cin >> W >> H;
  cout << fixed << setprecision(1) << W * H / 2;
}
