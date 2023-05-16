#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int d[102][100002];
int w[102];
int v[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K; 
    for (int i=1; i<=N; i++){
        cin >> w[i];
        cin >> v[i];
    }

    for (int i=1; i<=N; i++){
        for (int j=1; j<=K; j++){
            if (w[i] <= j) { // 담을 수 있음 (선택 가능)
                d[i][j] = max(d[i-1][j], d[i-1][j-w[i]] + v[i]);
            } else { // 담을 수 없음
                d[i][j] = d[i-1][j];
            }
        }
    }
    cout << d[N][K];

    return 0;
}
