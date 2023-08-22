#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    stack<char> s;
    int cnt = 0;
    for (int i=0; i<number.size(); i++){
        while (!s.empty() && s.top() < number[i] && cnt < k){
            s.pop();
            cnt++;
        }
        s.push(number[i]);
    }
    
    while (cnt++ < k) s.pop();
    while (!s.empty()){
        answer = s.top() + answer;
        s.pop();
    }
    
    return answer;
}
