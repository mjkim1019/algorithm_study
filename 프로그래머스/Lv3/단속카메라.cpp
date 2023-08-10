#include <bits/stdc++.h>
using namespace std;

// 구하는 것 : 모든 차량이 카메라 만나도록 최소 몇 대의 카메라를 설치해야 하는지
// 해결법 : 최대한 겹치는대로

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
   
    int st = routes[0][0];
    int en = routes[0][1];
    answer++;
    for (int i=1; i<routes.size(); i++){
        if (en < routes[i][0] || st > routes[i][1]) { // 범위 안겹침
            answer++;
            st = routes[i][0];
            en = routes[i][1];
            continue;
        }
        // 범위 겹침
        st = max(st, routes[i][0]);
        en = min(en, routes[i][1]);
    }
    
    return answer;
}
