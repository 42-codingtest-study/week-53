#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string answer = "";
    multiset <string> list;
    for(int i =0; i< participant.size(); i++)
    {
        list.insert(participant[i]);
    }
    
    for(int i =0; i< completion.size(); i++)
    {
        auto finded = list.find(completion[i]);
        list.erase(finded);
    }
    //cout<<*list.begin();
    answer = *list.begin();
    return answer;
}