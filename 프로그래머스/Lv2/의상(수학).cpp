#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    for (auto cloth: clothes){
        m[cloth[1]]++;
    }
    //for (auto c: m) cout << c.first << ' ' << c.second <<'\n';
    
    for (auto it = m.begin(); it != m.end(); it++){
        answer *= (it->second+1); // 가지수+안입을 경우의 수
    }
    
    return answer-1; // 적어도 하나는 입어야하므로
}
