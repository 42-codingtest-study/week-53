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
  int n;
  cin >> n;
  map<int, pair<int, int>> m = {
      {1, {12, 1600}}, {2, {11, 894}}, {3, {11, 1327}}, {4, {10, 1311}},
      {5, {9, 1004}},  {6, {9, 1178}}, {7, {9, 1357}},  {8, {8, 837}},
      {9, {7, 1055}},  {10, {6, 556}}, {11, {6, 773}}};
  cout << m[n].first << " " << m[n].second;
}
