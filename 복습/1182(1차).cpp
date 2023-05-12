#include <iostream>
using namespace std;

int N, S;
int arr[25];
int ans;

void dfs(int L, int sum)
{
    if (L == N)
    {
        if (sum == S) ans++;
        return;
    }

    dfs(L + 1, sum);
    dfs(L + 1, sum + arr[L]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    dfs(0, 0);
    if (S == 0)
        ans--;
    cout << ans;

    return 0;
}
