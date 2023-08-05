#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];

int bfs(int st, int n, int ex){
    int cnt = 0;
    vector<bool> vis(n+1, false);
    queue<int> q;
    q.push(st);
    vis[st] = true;
    //cnt++;
    while (!q.empty()){
        cnt++;
        int cur = q.front(); q.pop();
        for (int &v : adj[cur]) {
            if ((cur==st && v==ex) || (cur==ex && v==st)) continue;
            if (vis[v]) continue;
            //cout << cur << " - " << v <<'\n';
            q.push(v);
            vis[v] = true;
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n+1;
    
    for (auto w: wires){
        adj[w[0]].push_back(w[1]);
        adj[w[1]].push_back(w[0]);
    }
    
    for (int a=1; a<=n; a++){
        for (int &b: adj[a]){ // a-b 간선 선택
            if (a > b) continue;
            int k = bfs(a, n, b);
            answer = min(answer, abs(k- (n-k)));
            if (answer == 0) return 0;
            //cout << a <<"~" << b <<"연결해제 : "<< k << '\n';
        }
    }
    
    return answer;
}
