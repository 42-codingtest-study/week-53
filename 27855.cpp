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
  int H1, B1, H2, B2;
  cin >> H1 >> B1 >> H2 >> B2;
  int score1 = H1 * 3 + B1, score2 = H2 * 3 + B2;
  int score = abs(score1 - score2);
  cout << (score1 > score2 ? "1 " : score1 < score2 ? "2 " : "NO SCORE");
  if (score1 != score2) cout << score;
}
