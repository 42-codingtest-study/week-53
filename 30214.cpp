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
  int S1, S2;
  cin >> S1 >> S2;
  cout << (S1 * 2 >= S2 ? 'E' : 'H');
}
