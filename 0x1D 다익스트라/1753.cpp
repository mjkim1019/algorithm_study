#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second
#define INF 1e9

vector<pair<int, int>> adj[20005]; // {비용, 정점}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 최소힙
int d[20005];

void dijkstra(int st){
    pq.push({d[st], st});
    
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (d[cur.Y] != cur.X) continue;
        //cout << cur.X << ' ' << cur.Y <<'\n';

        for (auto &v: adj[cur.Y]){
            if (d[v.Y] > d[cur.Y] + v.X) {
                d[v.Y] = d[cur.Y] + v.X;
                pq.push({d[v.Y], v.Y});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V, E; cin >> V >> E;
    int K; cin >> K;
    while (E--){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    fill(d+1, d+V+1, INF);
    d[K] = 0;
    dijkstra(K);
    for (int i=1; i<=V; i++) {
        if (d[i] == INF) cout << "INF" <<'\n';
        else cout << d[i] <<'\n';
    }
}
