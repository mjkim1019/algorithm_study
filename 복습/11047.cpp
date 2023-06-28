#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    
    vector<int> money(N);
    for (int i=0; i<N; i++) cin >> money[i];

    for (int i=N-1; i>=0; i--){
        if (K <=0) break;
        if (K < money[i]) continue;
        ans += K / money[i];
        K %= money[i];
    }

    cout << ans;

    return 0;
}
