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
  int N, D = 0, P = 0;
  char c;
  cin >> N;
  while (N--) {
    cin >> c;
    if (abs(D - P) >= 2) continue;
    if (c == 'D')
      D++;
    else
      P++;
  }
  cout << D << ":" << P;
}
