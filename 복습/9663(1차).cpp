#include <iostream>
using namespace std;

bool isUsed1[20];
bool isUsed2[35];
bool isUsed3[35];

int N;
int ans = 0;

void dfs(int L){
    if (L == N){
        ans++;
        return;
    }

    for (int j=0; j<N; j++){
        if (isUsed1[j] || isUsed2[L+j] || isUsed3[L-j+N-1]) continue;
        isUsed1[j] = true;
        isUsed2[L+j] = true;
        isUsed3[L-j+N-1] = true;
        dfs(L + 1);
        isUsed1[j] = false;
        isUsed2[L + j] = false;
        isUsed3[L - j + N - 1] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    dfs(0);
    cout << ans;

    return 0;
}
