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

bool divisble42(string s) {
  int n = 0;
  for (int i = 0; i < s.size(); i++) {
    n = (n * 10 + s[i] - '0') % 42;
  }
  return n == 0;
}

int main() {
  fast;
  string n;
  while (cin >> n) {
    if (n == "0") break;
    cout << (!divisble42(n) ? "TENTE NOVAMENTE" : "PREMIADO") << endl;
  }
}
