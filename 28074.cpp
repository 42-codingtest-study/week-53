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
  string s;
  cin >> s;
  cout << (s.find("M") != s.npos && s.find("O") != s.npos &&
                   s.find("B") != s.npos && s.find("I") != s.npos &&
                   s.find("S") != s.npos
               ? "YES"
               : "NO");
}
