#include <iostream>
using namespace std;

int d[20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 초기값 정하기
    d[1] = 1; d[2] = 2; d[3] = 4;
    // n이 주어질 때마다 매번 새로 d[1]부터 d[n]까지 구하는 것보다 미리 다 구해두는 게 효율적!
    for (int i = 4; i < 11; i++)
    {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }

    int TC;
    cin >> TC;
    while (TC--){
        int N;
        cin >> N;
        cout << d[N] << '\n';
    }

    return 0;
}
