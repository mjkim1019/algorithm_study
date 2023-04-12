#include <iostream>
using namespace std;

int d[20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while (TC--){
        int N;
        cin >> N;

        // 초기값 정하기
        d[1] = 1; d[2] = 2; d[3]=4;
        for (int i=4; i<=N; i++){
            d[i] = d[i-1] + d[i-2] + d[i-3];
        }
        cout << d[N] << '\n';
    }

    return 0;
}
