#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end()); // 1 1 1 2 2 5

    ll ans = v[0];
    int mxCnt = 0;
    int cnt = 1;
    for (int i = 1; i < N; i++)
    {
        if (v[i - 1] == v[i])
            cnt++;
        else
        {
            if (mxCnt < cnt)
            {
                mxCnt = cnt;
                ans = v[i - 1];
            }
            cnt = 1;
        }
    }
    if (mxCnt < cnt) ans = v[N - 1];

    cout << ans;

    return 0;
}
