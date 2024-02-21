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

int rounds(double n) { return (int)(n + 0.5); }

int main() {
  fast;
  double N;
  cin >> N;
  if (N == 0) {
    cout << 0 << '\n';
    return 0;
  }
  double cut = rounds(N * 0.15);
  vector<int> arr;
  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }
  sort(arr.begin(), arr.end());
  int sum = 0;
  for (int i = cut; i < N - cut; i++) {
    sum += arr[i];
  }
  cout << rounds(sum / (N - 2 * cut)) << '\n';
}
