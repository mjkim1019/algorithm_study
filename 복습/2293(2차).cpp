#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> coin(N);
    for (int i=0; i<N; i++) cin >> coin[i];
    sort(coin.begin(), coin.end());

    d[0] = 1;
    for (int i= 0; i<N; i++){
        for (int k = coin[i]; k<=K; k++){
            d[k] += d[k-coin[i]];
        }
    }
    cout << d[K];

    return 0;
}
