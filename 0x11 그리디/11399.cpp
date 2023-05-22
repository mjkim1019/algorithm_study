#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i=0; i<N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<int> d(N);
    d[0] = arr[0];
    for (int i=1; i<N; i++){
        d[i] = d[i-1] + arr[i];
    }

    int ans = 0;
    for (int i=0; i<N; i++) ans += d[i];
    cout << ans;

    return 0;
}
