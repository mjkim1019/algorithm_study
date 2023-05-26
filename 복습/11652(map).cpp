#include <iostream>
#include <map>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    map<ll, int> m;
    for (int i=0; i<N; i++) {
        ll tmp; cin >> tmp;
        m[tmp]++;
    }
    int mx = 0;
    ll ans;
    for (auto i: m){
        //cout << i.first << ' ' <<i.second <<'\n';
        if (mx < i.second) {
            mx = i.second;
            ans = i.first;
        }
    }
    cout << ans;

    return 0;
}
