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

#include <iostream>
#include <string>

bool contain7(string s) { return s.find('7') != string::npos; }
bool divisible7(int n) { return n % 7 == 0; }
int solve(int n, string s) {
  if (!contain7(s) && !divisible7(n))
    return 0;
  else if (!contain7(s))
    return 1;
  else if (!divisible7(n))
    return 2;
  else
    return 3;
}

int main() {
  fast;
  int N;
  string s;
  cin >> s;
  N = std::stoi(s);
  cout << solve(N, s);
}
