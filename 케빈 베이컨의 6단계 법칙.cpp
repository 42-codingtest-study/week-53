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
  int N, M, x, y;
  cin >> N >> M;
  vector<vector<int>> board(N, vector<int>(N, 0));
  for (int i = 0; i < M; i++) {
    cin >> x >> y;
    board[x - 1][y - 1] = 1, board[y - 1][x - 1] = 1;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (j != k && board[j][i] && board[i][k])
          board[j][k] = board[j][k] == 0
                            ? board[j][i] + board[i][k]
                            : min(board[j][k], board[j][i] + board[i][k]);
      }
    }
  }
  int answer = 0, allSum = 0;
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      sum += board[i][j];
    }
    if (sum < allSum || !allSum) allSum = sum, answer = i + 1;
  }
  cout << answer;
}
