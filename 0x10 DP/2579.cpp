#include <iostream>
using namespace std;

int s[302];
int d[302][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i=1; i<=N; i++) cin >> s[i];

    // 예외처리
    if( N == 1) {
        cout<< s[1];
        return 0;
    }

    // 초기값 세팅
    d[2][1] = s[2];
    d[1][2] = 0;
    d[1][1] = s[1];
    d[2][2] = s[1] + s[2];

    for (int k=3; k<=N; k++){
        d[k][1] = max(d[k-2][1], d[k-2][2]) + s[k]; // 2칸 뛰기
        d[k][2] = d[k-1][1] + s[k]; // 1칸 뛰기
    }

    cout << max(d[N][1], d[N][2]);

    return 0;
}
