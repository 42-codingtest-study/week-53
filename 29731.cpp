#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

int main() {
  fast;
  unordered_set<string> v = {"Never gonna give you up",
                             "Never gonna let you down",
                             "Never gonna run around and desert you",
                             "Never gonna make you cry",
                             "Never gonna say goodbye",
                             "Never gonna tell a lie and hurt you",
                             "Never gonna stop"};
  int n;
  string s;
  cin >> n;
  cin.ignore();
  bool t = true;
  while (n--) {
    getline(cin, s);
    if (v.find(s) == v.end()) t = false;
  }
  cout << (!t ? "Yes" : "No");
}
