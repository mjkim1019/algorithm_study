#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a = 1e9 + 1, b = 1e9 + 1;

    int N; cin >> N;
    vector<int> arr(N);
    for (int i=0; i<N; i++) cin >> arr[i];

    for (int i=0; i<N; i++){
        int idx = lower_bound(arr.begin() + i, arr.end(), -arr[i]) - arr.begin();
        // 최솟값은 idx-1, idx, idx+1에서 결정남
        int k = idx;
        if (k < arr.size() && k != i && abs(arr[k] + arr[i]) < abs(a + b)){
            a = arr[k];
            b = arr[i];
        }
        k = idx+1;
        if (k < arr.size() && k != i && abs(arr[k] + arr[i]) < abs(a+b)){
            a = arr[k];
            b = arr[i];
        }
        k = idx-1;
        if (k >= 0 && k != i && abs(arr[k]+arr[i]) < abs(a+b)){
            a = arr[k];
            b = arr[i];
        }
    }

    if (a > b) swap(a, b);
    cout << a  << ' ' << b;

    return 0;
}
