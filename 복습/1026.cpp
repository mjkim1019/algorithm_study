#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    for (int i=0; i<N; i++) cin >> a[i];
    for (int i=0; i<N; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());

    int ans = 0;
    for (int i=0; i<N; i++){
        ans += a[i]*b[i];
    }
    cout << ans;

    return 0;
}
