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
  int t1, e1, f1, t2, e2, f2, max = 0, mel = 0;
  cin >> t1 >> e1 >> f1 >> t2 >> e2 >> f2;
  max += t1 * 3 + e1 * 20 + f1 * 120;
  mel += t2 * 3 + e2 * 20 + f2 * 120;
  cout << (max > mel ? "Max" : (max < mel ? "Mel" : "Draw"));
}
