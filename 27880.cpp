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
  int n, answer = 0;
  for (int i = 0; i < 4; i++) {
    cin >> s >> n;
    answer += s == "Es" ? n * 21 : n * 17;
  }
  cout << answer;
}
