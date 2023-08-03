#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e8
using namespace std;
#define X first
#define Y second

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최소힙
int d[1005];
vector<pair<int, int> > adj[1005]; // {비용, 정점}
int pre[1005];                   // 경로

void dijkstra(int st){
    d[st] = 0;
    pq.push({d[st], st});
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (cur.X != d[cur.Y]) continue;
        for (auto &nxt : adj[cur.Y]){
            if (d[nxt.Y] > d[cur.Y] + nxt.X){
                d[nxt.Y] = d[cur.Y] + nxt.X;
                pq.push({d[nxt.Y], nxt.Y});
                pre[nxt.Y] = cur.Y;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    while (m--){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    fill(d + 1, d + 1 + n, INF);

    int a, b;
    cin >> a >> b;
    dijkstra(a);
    cout << d[b] << '\n';
    vector<int> path;
    int cur = b;
    while (cur != a){
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(a);
    cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << ' ';

    return 0;
}
