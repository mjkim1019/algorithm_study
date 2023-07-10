#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> d(N+1);
    vector<int> pre(N+1);

    d[1] = 0;
    for (int i=2; i<=N; i++){
        d[i] = d[i-1]+1;
        pre[i] = i-1;
        if (i%2 == 0 && d[i] > d[i/2]+1) {
            d[i] = d[i/2]+1;
            pre[i] = i/2;
        }
        if (i%3 == 0 && d[i] > d[i/3]+1) {
            d[i] = min(d[i/3]+1, d[i]);
            pre[i] = i/3;
        }
    }
    cout << d[N] << '\n';
    int cur = N;
    while (cur != 1){
        cout << cur << ' ';
        cur = pre[cur];
    }
    cout << 1;

    return 0;
}
