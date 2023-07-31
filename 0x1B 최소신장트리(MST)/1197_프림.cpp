#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p(100005, -1);

int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]); // 경로압축
}

bool is_diff_group(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return false; // 같은 그룹
    // 다른 그룹이면 더 작은 값에 합치기
    if (u < v) p[v] = u;
    else p[u] = v;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;
    int V, E;
    cin >> V >> E;
    tuple<int, int, int> edge[100005]; // 비용, 정점1, 정점2
    for (int i=0; i<E; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};    
    }

    sort(edge, edge+E); // 오름차순 정렬
    int cnt = 0;
    for (int i=0; i<E; i++){
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b)) continue;
        answer += cost;
        cnt++;
        if (cnt == V-1) break;
    }
    cout << answer;

    return 0;
}
