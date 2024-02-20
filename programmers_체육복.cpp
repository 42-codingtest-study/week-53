#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <stdio.h>
#include <map>
// #include <string.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
  int answer = 0;
  int clothes_num[32];
  int clothes_num2[32];
  // sort(lost.begin(), lost.end());
  // sort(reserve.begin(), reserve.end());

  // memset(clothes_num, 0, n);

  for (int i = 0; i < n; i++)
  {
    // cout<<lost[i]<<'\n';
    clothes_num[i] = 1;
    clothes_num2[i] = 1;
  }

  for (int i = 0; i < lost.size(); i++)
  {
    // cout<<lost[i]<<'\n';
    clothes_num[lost[i] - 1]--;
    clothes_num2[lost[i] - 1]--;
  }

  for (int i = 0; i < reserve.size(); i++)
  {
    // cout<<reserve[i]<<'\n';
    clothes_num[reserve[i] - 1]++;
    clothes_num2[reserve[i] - 1]++;
  }
  /*
  for(int i =0; i< n; i++)
  {
      cout<<clothes_num[i] <<'\n';
  }*/

  for (int i = 1; i < n; i++)
  {
    if (clothes_num[i] == 0) // 양옆 새끼들중에 2인 애 찾기
    {
      if (clothes_num[i - 1] > 1)
      {
        clothes_num[i - 1]--;
        clothes_num[i]++;
      }
    }
  }
  for (int i = n - 2; i >= 0; i--)
  {
    if (clothes_num[i] == 0)
    {
      if (clothes_num[i + 1] > 1)
      {
        clothes_num[i + 1]--;
        clothes_num[i]++;
      }
    }
  }

  for (int i = n - 2; i >= 0; i--)
  {
    if (clothes_num2[i] == 0)
    {
      if (clothes_num2[i + 1] > 1)
      {
        clothes_num2[i + 1]--;
        clothes_num2[i]++;
      }
    }
  }
  for (int i = 1; i < n; i++)
  {
    if (clothes_num2[i] == 0) // 양옆 새끼들중에 2인 애 찾기
    {
      if (clothes_num2[i - 1] > 1)
      {
        clothes_num2[i - 1]--;
        clothes_num2[i]++;
      }
    }
  }

  int ans = 0;
  int ans2 = 0;
  for (int i = 0; i < n; i++)
  {
    if (clothes_num[i] >= 1)
      ans++;
    if (clothes_num2[i] >= 1)
      ans2++;
  }
  if (ans > ans2)
    return ans;
  else
    return ans2;
}