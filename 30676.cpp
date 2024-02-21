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
  if (n >= 620)
    cout << "Red";
  else if (n >= 590)
    cout << "Orange";
  else if (n >= 570)
    cout << "Yellow";
  else if (n >= 495)
    cout << "Green";
  else if (n >= 450)
    cout << "Blue";
  else if (n >= 425)
    cout << "Indigo";
  else
    cout << "Violet";
}
