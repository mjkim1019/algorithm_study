#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<>> pq; // 최소힙
    for (auto &sc: scoville) pq.push(sc);
  
    while (pq.size() > 1){
        if (pq.top() >= K) return answer;
        
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a + 2*b);
        answer++;
    }
    
    if (pq.top() >= K) return answer;
    
    return -1;
}
