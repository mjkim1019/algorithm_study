#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e8+1
#define X first
#define Y second

vector<pair<int, int>> adj[1001]; // 정점1 : {비용, 정점2}
int d[1001];
int pre[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a, b, c;
    while (m--){
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    int st, en;
    cin >> st >> en; // 출발지, 도착지 존재 -> 다익스트라
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // {비용, 정점2}
    fill(d+1, d+n+1, INF);
    d[st] = 0;
    pq.push({d[st], st});
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (cur.X != d[cur.Y]) continue;

        for (auto &e: adj[cur.Y]){
            if (e.X + d[cur.Y] < d[e.Y]) {
                d[e.Y] = e.X + d[cur.Y];
                pq.push({d[e.Y], e.Y});
                pre[e.Y] = cur.Y;
            }
        }
    }
    cout << d[en] <<'\n';
    vector<int> path;
    int pos = en;
    while (pos != st){
        path.push_back(pos);
        pos = pre[pos];
    }
    path.push_back(st);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (auto &p: path) cout << p << ' ';

    return 0;
}
