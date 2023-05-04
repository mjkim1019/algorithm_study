#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[12];
int op[4]; // +, -, *, / 개수
int mx = -1000000000;
int mn = 1000000000;

void dfs(int res, int L){
    if (L == N){
        mx = max(mx, res);
        mn = min(mn, res);
        return;
    }

    for (int i=0; i<4; i++){
        if (!op[i]) continue;
        op[i]--;
        if (i == 0) dfs(res + arr[L], L+1);
        else if (i == 1)
            dfs(res - arr[L], L+1);
        else if (i == 2)
            dfs(res*arr[L], L+1);
        else if (i == 3)
            dfs(res / arr[L], L+1);
        
        op[i]++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    for (int i=0; i<4; i++) cin >> op[i];
    
    dfs(arr[0], 1);
    cout << mx << '\n' << mn;

    return 0;
}
