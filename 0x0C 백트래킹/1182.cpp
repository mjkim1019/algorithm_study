#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int input[21];
int ans = 0;

void func(int L, int sum) {
    if (L == N){
        if (sum == S) ans++;
        return;
    }
    
    func(L+1, sum);
    func(L+1, sum + input[L]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for (int i=0; i<N; i++) cin >> input[i];
    func(0, 0);
    if (S == 0) ans--; // 공집합이 답에 추가되는 경우는 S가 0일때만
    cout << ans;

    return 0;
}
