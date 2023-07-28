#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> S;
    S.push(number[0]);
    for (int i=1; i<number.size(); i++){
        while (k >0 && !S.empty() && number[i] > S.top()){
            S.pop(); k--;
        }
        S.push(number[i]);
    }
    if (k-- > 0 && !S.empty()) S.pop();
    while (!S.empty()){
        char c = S.top(); S.pop();
        answer = c + answer;
    }
    return answer;
}
