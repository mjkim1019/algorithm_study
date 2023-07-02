#include <bits/stdc++.h>

using namespace std;

int hambuger[4] = {1, 3, 2, 1};

int solution(vector<int> ingredient) {
    int answer = 0;
    
    stack<int> S;
    for (int i=0; i<ingredient.size(); i++){
        S.push(ingredient[i]);
        if (S.size() <4) continue;
        
        stack<int> S2;
        int cnt = 0;
        while (!S.empty() && cnt < 4){
            if (S.top() != hambuger[cnt]) break;
            S2.push(S.top()); S.pop();
            cnt++;
        }
        if (cnt == 4) answer++;
        else {
            while (!S2.empty()){
                S.push(S2.top()); 
                S2.pop();
            }
        }
    }
    
    return answer;
}
