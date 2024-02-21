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
  int N, A, B, X;
  cin >> N;
  while (N--) {
    cin >> A >> B >> X;
    cout << (A * (X - 1) + B) << endl;
  }
}
