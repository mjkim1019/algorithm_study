#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[51];
int b[51];
int ans;

bool cmp(int x1, int x2){
    return x1 > x2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; i++) cin >> a[i];
    for (int i=0; i<N; i++) cin >> b[i];
    
    sort(a, a+N);
    sort(b, b+N, cmp);
    for (int i = 0; i < N; i++)
        ans += a[i] * b[i];
    
    cout << ans;

    return 0;
}
