#include <iostream>

using namespace std;

void func(int a, int b, int n) {
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    // n-1개의 원판 a -> (6-a-b)
    func(a, 6-a-b, n-1);
    // n번째 원판 a -> b
    cout << a << ' ' << b << '\n'; 
    // n-1개의 원판 (6-a-b) -> b
    func(6-a-b, b, n-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    cout << (1 << N) - 1 << '\n';
    func(1, 3, N);

    return 0;
}
