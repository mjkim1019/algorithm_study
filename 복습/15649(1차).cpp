#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool vis[10];
int ans[10];

void dfs(int L){
    if (L == M){
        for (int i=0; i<M; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i=1; i<=N; i++){
        if (!vis[i]) {
            ans[L] = i;
            vis[i] = true;
            dfs(L+1);
            vis[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    dfs(0);
    
    return 0;
}
