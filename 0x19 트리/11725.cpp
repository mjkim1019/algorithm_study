#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[100001];
int parent[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i=1; i<N; i++){ // 노드 개수 N, 간선 개수 N-1
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int cur = q.front(); q.pop();
        for (int &nxt: tree[cur]){
            if (nxt == parent[cur]) continue;
            q.push(nxt);
            parent[nxt] = cur;
        }
    }

    for (int i=2; i<=N; i++) cout << parent[i] <<'\n';

    return 0;
}
