#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int N, M, V;
vector<int> adj[1001];
bool vis[1001];

void bfs(){
    queue<int> q;
    q.push(V);
    vis[V] = true;
    while (!q.empty()){
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (auto nxt: adj[cur]){
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

void dfs(int cur)
{
    cout << cur << ' ';
    vis[cur] = true;

    for (auto nxt : adj[cur])
    {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

void dfs2(){
    vector<bool> vis(N + 1, false);
    stack<int> s;
    s.push(V);
    while (!s.empty()){
        int cur = s.top(); s.pop();
        if (vis[cur]) continue;
        cout << cur << ' ';
        vis[cur] = true;
        for (int i=0; i<adj[cur].size(); i++){ // 스택 특성상 역순으로 정점을 넣어야 작은 정점을 먼저 순회함
            int nxt = adj[cur][adj[cur].size()-1-i];
            if (vis[nxt]) continue;
            s.push(nxt);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> V;
    while (M--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=N; i++)
        sort(adj[i].begin(), adj[i].end());


    dfs(V);
    cout << '\n';
    fill(vis+1, vis+N+1, false);
    dfs2();
    cout << '\n';
    fill(vis+1, vis+N+1, false);
    bfs();
   

    return 0;
}
