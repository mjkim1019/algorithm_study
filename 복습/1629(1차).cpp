#include <iostream>
using namespace std;

int Pow(int a, int b, int c){
    if (b == 1) return a%c;

    long long val = Pow(a, b/2, c);
    val = val * val % c;
    if (b % 2 == 0) return val;
    return val * a % c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    cout << Pow(a, b, c);

    return 0;
}
