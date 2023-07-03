#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, x, y;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
        int answer = -1;
        cin >> M >> N >> x >> y;

        // 0. 나머지 연산할 것이므로 전처리
        if (x == M) x = 0;
        if (y == N) y = 0;

        // 1. 최소공배수 구하기
        int LCM = M*N / gcd(M, N);
        //cout << LCM <<'\n';

        // 2. 답 구하기
        for (int i = x; i<= LCM; i += M){
            if (i == 0) continue;
            if (i % N == y) answer = i;
        }
        cout << answer <<'\n';
    }

    return 0;
}
