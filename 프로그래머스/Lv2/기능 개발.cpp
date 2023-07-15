#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    stack<int> S;
    for (int i= speeds.size()-1; i>=0; i--){
        int task = 0;
        task += (100 - progresses[i]) / speeds[i];
        if (((100 - progresses[i]) % speeds[i]) != 0) task++;
        S.push(task);
    }
    
    while (!S.empty()){
        int day = S.top(); S.pop();
        int cnt = 1;
        while (!S.empty() && S.top() <= day) {
            S.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}
