#include <iostream>
using namespace std;

int func(int n, int r, int c){
    if (n == 0) return 0;

    int half = 1 << (n-1);
    if (half > r && half > c) return func(n-1, r, c);
    else if (half > r && half <= c) return half*half + func(n-1, r, c - half);
    else if (half <= r && half > c) return 2*half*half + func(n-1, r-half, c);
    else return 3*half*half + func(n-1, r-half, c-half);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c;
    cin >> N >> r >> c;
    cout  << func(N, r, c);

    return 0;
}
