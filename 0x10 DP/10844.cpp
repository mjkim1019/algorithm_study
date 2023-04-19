#include <iostream>
#include <algorithm>
#define mod 1000000000
using namespace std;

// d[i][k] = i자리이면서 끝자리가 k인 계단수의 개수
int d[102][10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    // 초기값 설정
    for (int i=1; i<=9; i++) d[1][i] = 1;

    for (int i=2; i<=N; i++){
        for (int j= 0; j<=9; j++){
            if (j != 0) d[i][j] += d[i-1][j-1];
            if (j != 9) d[i][j] += d[i-1][j+1];
            d[i][j] %= mod;
        }
    }

    long long ans = 0;
    for (int i=0; i<=9; i++) ans += d[N][i];
    cout << ans % mod;


    return 0;
}
