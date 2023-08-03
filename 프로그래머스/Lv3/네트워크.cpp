#include <bits/stdc++.h>
using namespace std;

vector<int> adj[205];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i <= j || !computers[i][j]) continue;
            adj[i+1].push_back(j+1); // 1부터 시작하도록 변경
            adj[j+1].push_back(i+1);
        }
    }
    
    vector<bool> vis(n+1, false);
    for (int i=1; i<=n; i++){
        if (vis[i]) continue;
        //cout << i << ' ';
        answer++;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while (!q.empty()){
            int cur = q.front(); q.pop();
            for (int &v: adj[cur]){
                if (vis[v]) continue;
                q.push(v);
                vis[v] = true;
            }
        }
    }
    
    return answer;
}
