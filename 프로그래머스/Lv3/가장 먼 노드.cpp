#include <bits/stdc++.h>
using namespace std;
#define INF 50000+10
#define X first
#define Y second

vector<int> adj[20005];
int d[20005];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (auto e: edge){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    fill(d+1, d+n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 비용, 노드
    d[1] = 0;
    pq.push({d[1], 1});
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (d[cur.Y] != cur.X) continue;
        
        for (auto x: adj[cur.Y]){
            if (d[x] > d[cur.Y] + 1){
                d[x] = d[cur.Y]+1;
                pq.push({d[x], x});
            }
        }
    }
    
    int mx = *max_element(d+1, d+n+1);
    cout << mx <<'\n';
    for (int i=1; i <= n; i++) {
        //cout << d[i] <<'\n';
        if (mx == d[i]) answer++;
    }
    
    return answer;
}
