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
  int n;
  cin >> n;
  string s;
  cin.ignore();
  while (n--) {
    getline(cin, s);
    cout << s;
    if (s.substr(s.size() - 1, 1) != ".") cout << ".";
    cout << "\n";
  }
}
