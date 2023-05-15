#include <iostream>
using namespace std;

int N, K;
int arr[11];
int ans = 0;
int mxidx;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
        if (arr[i] <= K) mxidx = i;
    }

    for (int i=mxidx; i>=0; i--){
        int price = arr[i];
        ans += K / price;
        K %= price;
        if (K == 0) break;
    }

    cout << ans;

    return 0;
}
