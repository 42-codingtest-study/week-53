#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0);

int precedence(char op) {
  if (op == '(') return 0;
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return -1;
}

int main() {
  fast;
  string s;
  cin >> s;
  string result;
  stack<char> opStack;
  for (char ch : s) {
    if (ch >= 'A' && ch <= 'Z')
      result += ch;
    else if (ch == '(')
      opStack.push(ch);
    else if (ch == ')') {
      while (!opStack.empty() && opStack.top() != '(')
        result += opStack.top(), opStack.pop();
      opStack.pop();
    } else {
      while (!opStack.empty() && precedence(opStack.top()) >= precedence(ch))
        result += opStack.top(), opStack.pop();
      opStack.push(ch);
    }
  }
  while (!opStack.empty()) result += opStack.top(), opStack.pop();
  cout << result;
}
