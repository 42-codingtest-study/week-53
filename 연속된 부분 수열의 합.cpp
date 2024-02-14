#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minSeq = 2147483647;

vector<int> solution(vector<int> sequence, int k) {
  int start = 0, end = 0, sum = sequence[0], minLen = sequence.size() + 1;
  vector<int> answer = {-1, -1};
  while (start < sequence.size() && end < sequence.size()) {
    if (sum < k) {
      end++;
      if (end < sequence.size()) sum += sequence[end];
    } else if (sum > k)
      sum -= sequence[start], start++;
    else {
      if (end - start + 1 < minLen)
        minLen = end - start + 1, answer[0] = start, answer[1] = end;
      sum -= sequence[start], start++;
    }
  }
  return answer;
}
