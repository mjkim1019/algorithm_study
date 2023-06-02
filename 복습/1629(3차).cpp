#include <iostream>
using namespace std;

long long func(int a, int b, int c){
    if (b == 1) return a %c;

    long long val = func(a, b/2,c);
    val = val * val %c;
    if (b % 2 == 1) val = (val * a) %c;
    return val%c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    cout << func(a, b, c);

    return 0;
}
