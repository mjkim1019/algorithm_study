#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
        long long ans = 0;

        int N;
        cin >> N;
        vector<int> v(N);
        for (int i=0; i<N; i++) cin >> v[i];

        int mx = v[N-1];
        for (int i=N-2; i>=0; i--){
            if (mx < v[i]) mx = v[i];
            ans += mx - v[i];
        }
        cout << ans << '\n';
    }

    return 0;
}
