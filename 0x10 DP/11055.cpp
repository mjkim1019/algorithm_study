#include <iostream>
#include <algorithm>
using namespace std;

int a[1002];
int d[1002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
        d[i] = a[i]; // 초기값 설정
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (d[j] < d[i]) d[i] = max(d[j]+a[i], d[i]);
        }
    }
    cout << *max_element(d, d+n);

    return 0;
}
