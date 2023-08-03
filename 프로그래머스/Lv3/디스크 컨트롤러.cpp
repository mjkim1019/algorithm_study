#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // 최소힙 {소요시간, 요청 시각} 
    int i=0;
    int t=0;
    while (i < jobs.size() || !pq.empty()){
        while (i < jobs.size() && t >=jobs[i][0]){
            pq.push({jobs[i][1], jobs[i][0]}); //{소요시간, 요청 시각}
            i++;
        }
        if (!pq.empty()){
            auto cur = pq.top(); pq.pop();
            t += cur.X;
            answer += t - cur.Y;
        
            //cout << "t = " << t <<'\n';
        }
        else {
            t = jobs[i][0];
        }
    
    }
    
    return (int)answer/jobs.size();
}
