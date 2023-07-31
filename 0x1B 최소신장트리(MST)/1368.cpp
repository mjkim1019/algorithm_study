#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p(305, -1);

int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return false;

    if (u < v) p[v] = u;
    else p[u] = v;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;

    int N;
    cin >> N;
    vector<tuple<int, int, int>> edge; // {비용, 정점1, 정점2}

    for (int i=1; i<=N; i++){
        int tmp; cin >> tmp;
        edge.push_back({tmp, i, N+1}); // 가상의 정점(N+1)에 저장
    }

        
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            int cost; cin >> cost;
            if (i < j) continue;
            edge.push_back({cost, i, j});
        }
    }

    sort(edge.begin(), edge.end());
    int cnt = 0;
    for (int i=0; i<edge.size(); i++){
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b)) continue;
        cnt++;
        answer += cost;
        if (cnt == N) break; // 정점 이제 N+1개이므로 N개의 간선 선택해야함
    }
    cout << answer;

    return 0;
}
