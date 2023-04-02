#include <iostream>
using namespace std;

using ll = long long;

/*
a^b mod m
a^n * a^n = a^(2n)
k승을 계산했으면 2k승과 2k+1승도 O(1)에 계산할 수 있다
*/

ll POW(ll a, ll b, ll m){
    if (b == 1) return a % m;
    ll val = POW(a, b/2, m);
    val = val * val % m;
    if (b%2 == 0) return val;
    return val * a % m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << POW(a, b, c);

    return 0;
}
