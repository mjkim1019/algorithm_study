int indegree[10];
vector<int> adj[10];
int N; // 노드 수
vector<int> result;

// indegree 테이블 채우기
for (int i=1; i<=N; i++){
    for (int node: adj[i]){
        indegree[node]++;
    }
}

queue<int> q;
for (int i=1; i<=N; i++){
    if (indegree[i] == 0) q.push(i);
}

while (!q.empty()){
    int cur = q.front(); q.pop();
    result.push_back(cur);
    for (int &nxt: adj[cur]){
        if (--indegree[nxt] == 0) q.push(nxt);
    }
}

if (result.size() != N) cout << "recycle exists!";
else {
    for (auto x: result) cout << x << ' ';
}
