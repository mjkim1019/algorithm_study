#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    if (N==1) {
        cout << "0"; return 0;
    }

    d = vector<int> (N+1, 0);

    d[1] = 0;
    for (int i=2; i<=N; i++){
        d[i] = d[i-1]+1;
        if (i % 3 == 0) d[i] = min(d[i], d[i/3]+1);
        if (i % 2 == 0) d[i] = min(d[i], d[i/2]+1);  
    }
    cout << d[N];

    return 0;
}
