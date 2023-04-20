#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int a[1000002];
int b[1000002];
int ans[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> a[i];
    for (int i=0; i<M; i++) cin >> b[i];

    sort(a, a+N);
    sort(b, b+M);

    int ai = 0;
    int bi = 0;
    int i=0;
    for (i=0; i<N+M; i++){
        if (ai == N) ans[i] = b[bi++];
        else if (bi == M) ans[i] = a[ai++];
        else if (a[ai] <= b[bi])
            ans[i] = a[ai++];
        else
            ans[i] = b[bi++];
    }
    
    
    for (int i=0; i<N+M; i++) cout << ans[i] <<' ';

    return 0;
}
