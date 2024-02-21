#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)

void cleanQueue(priority_queue<int>& pq, map<int, int>& m) {
  while (!pq.empty() && m[pq.top()] <= 0) {
    m.erase(pq.top());
    pq.pop();
  }
}

void cleanQueue(priority_queue<int, vector<int>, greater<int>>& pq,
                map<int, int>& m) {
  while (!pq.empty() && m[pq.top()] <= 0) {
    m.erase(pq.top());
    pq.pop();
  }
}

int main() {
  fast;
  int T;
  cin >> T;
  while (T--) {
    priority_queue<int> maxPq;
    priority_queue<int, vector<int>, greater<int>> minPq;
    map<int, int> m;
    int k, n;
    char op;
    cin >> k;
    while (k--) {
      cin >> op >> n;
      if (op == 'I') {
        maxPq.push(n);
        minPq.push(n);
        m[n]++;
      } else if (n == 1) {
        cleanQueue(maxPq, m);
        if (!maxPq.empty()) {
          m[maxPq.top()]--;
          maxPq.pop();
        }
      } else {
        cleanQueue(minPq, m);
        if (!minPq.empty()) {
          m[minPq.top()]--;
          minPq.pop();
        }
      }
    }
    cleanQueue(maxPq, m);
    cleanQueue(minPq, m);
    if (maxPq.empty() || minPq.empty()) {
      cout << "EMPTY\n";
    } else {
      cout << maxPq.top() << ' ' << minPq.top() << '\n';
    }
  }
  return 0;
}
