#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

int main() {
  fast;
  map<char, string> club;
  club['M'] = "MatKor", club['W'] = "WiCys", club['C'] = "CyKor",
  club['A'] = "AlKor", club['$'] = "$clear";
  char c;
  cin >> c;
  cout << club[c];
}
