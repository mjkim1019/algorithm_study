#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll d[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(d+1, d+4, 1LL);
    fill(d+4, d+6, 2LL);
    //for (int i=0; i<6; i++) cout << d[i] <<' ';
    for (int k=6; k<=100; k++){
        d[k] = d[k-5] + d[k-1];
    }

    int TC;
    cin >> TC;
    while (TC--){
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }

    return 0;
}
