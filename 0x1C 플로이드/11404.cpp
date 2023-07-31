#include <iostream>
#include <algorithm>
using namespace std;
#define INF 10e7

int d[105][105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i=1; i<=N; i++) fill(d[i], d[i]+N+1, INF);
    
    while(M--){
        int a, b, cost;
        cin >> a >> b >> cost;
        d[a][b] = min(d[a][b], cost);
    }
    for (int i = 1; i <= N; i++) d[i][i] = 0;

    for (int k=1; k<=N; k++)
        for (int i=1; i<=N; i++)
            for (int j=1; j<=N; j++)
                d[i][j] = min(d[i][j], d[i][k]+ d[k][j]);
            

    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (d[i][j] == INF) cout << 0 << ' ';
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    

    return 0;
}
