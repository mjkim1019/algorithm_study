#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> adj[1001];
    for (int i=1; i<= M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // 무방향 그래프
    }

    int answer = 0;
    vector<bool> vis(N+1, false);
    for (int i=1; i<= N; i++){
        if (vis[i]) continue;
        answer++;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while (!q.empty()){
            int cur = q.front(); q.pop();
            for (auto nxt: adj[cur]){
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    cout << answer;

    return 0;
}
