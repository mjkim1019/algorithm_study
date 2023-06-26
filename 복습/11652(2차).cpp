#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> arr(N);
    for (int i=0; i<N; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    ll ans = arr[0];
    int mxcnt = 1;
    int cnt = 1;
    for (int i=1; i<N; i++){
        if (arr[i] == arr[i-1]) cnt++;
        else {
            if (mxcnt < cnt){
                ans = arr[i-1];
                mxcnt = cnt;
            }
            cnt = 1;
        }
    }
    if (mxcnt < cnt){
        ans = arr[N-1];
        mxcnt = cnt;
    }

    cout << ans;

    return 0;
}
