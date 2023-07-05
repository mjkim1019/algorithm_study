#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    stack<char> S;
    for (auto c: s){
        if (c == '(') S.push(c);
        else {
            if (S.empty()) return false;
            if (S.top() == '(') S.pop();
        }
    }
    if (S.empty()) return true;
    else return false;

}
