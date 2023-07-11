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

    int st = 0, en = 0;
    // for (st = 0; st<N; st++){
    //     while(en<N && arr[en]-arr[st] < M) en++;
    //     if (en == N) break;
    //     answer = min(answer, arr[en]-arr[st]);
    // }
    while (st<=en && en<N){
        if (arr[en] - arr[st] >= M){
            answer = min(answer, arr[en]-arr[st]);
            st++;
        } else en++;
    }
    cout << answer;

    return 0;
}
