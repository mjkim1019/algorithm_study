#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0x7f7f7f7f;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (int i=0; i<N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    for (int i=0; i<N; i++){
        int idx = lower_bound(arr.begin(), arr.end(), arr[i]+M)-arr.begin();
        if (idx != N) answer = min(answer, abs(arr[idx]-arr[i]));
    }
    cout << answer;

    return 0;
}
