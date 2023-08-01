#include <iostream>
#include <algorithm>
#include <vector>
#define INF 10e7+1
using namespace std;

int d[101][101];
int nxt[101][101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        fill(d[i]+1, d[i]+1+n, INF);
        fill(nxt[i]+1, nxt[i]+1+n, INF);
    }
    while (m--){
        int a, b, cost;
        cin >> a >> b >> cost;
        d[a][b] = min(d[a][b], cost);
        nxt[a][b] = b;
    }
    for (int i=1; i<=n; i++) d[i][i] = 0;

    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (d[i][j] <= d[i][k] + d[k][j]) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                nxt[i][j] = nxt[i][k];
            }
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (d[i][j] == INF) cout << 0 <<' ';
            else cout << d[i][j] <<' ';
        }
        cout << '\n';
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (d[i][j] == 0 || d[i][j] == INF) {
                cout << 0 <<'\n'; continue;
            }
            vector<int> path;
            int st = i;
            while (st != j){
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() <<' ';
            for (auto p: path) cout << p <<' ';
            cout <<'\n';
        }
    }

    return 0;
}
