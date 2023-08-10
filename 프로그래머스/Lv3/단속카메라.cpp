#include <bits/stdc++.h>
using namespace std;

// 구하는 것 : 모든 차량이 카메라 만나도록 최소 몇 대의 카메라를 설치해야 하는지
// 해결법 : 최대한 겹치는대로

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1]; // 빨리 나가는 순서대로 정렬
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    for (auto v: routes) cout << v[0] << ", " << v[1] <<'\n';
   
    int limit = -30001;
    for (int i=0; i<routes.size(); i++){
        if (limit < routes[i][0]){ // 진입점이 나가는 지점보다 크면 감시카메라 필요
            answer++;
            limit = routes[i][1];
        }
    }
    
    return answer;
}
