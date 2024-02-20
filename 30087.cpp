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
  map<string, string> m = {{"Algorithm", "204"},
                           {"DataAnalysis", "207"},
                           {"ArtificialIntelligence", "302"},
                           {"CyberSecurity", "B101"},
                           {"Network", "303"},
                           {"Startup", "501"},
                           {"TestStrategy", "105"}};
  int N;
  cin >> N;
  while (N--) {
    string s;
    cin >> s;
    cout << m[s] << endl;
  }
}
