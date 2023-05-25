#include <iostream>
using namespace std;
#define ll long long

ll func(int a, int b, int c){
    if (b == 1){
        return a%c;
    }

    ll val = func(a, b/2, c);
    val = val * val %c; 
    if (b %2 == 0) return val;
    else return a*val%c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    cout << func(A, B, C);

    return 0;
}
