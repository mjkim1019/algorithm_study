#include <iostream>
#define ll long long
using namespace std;

ll d[92][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    d[1][0] = 0; d[1][1] = 1;
    for (int k=2; k<=N; k++){
        d[k][0] = d[k-1][0] + d[k-1][1];
        d[k][1] = d[k-1][0];
    }
    cout << d[N][0] + d[N][1];
    
    return 0;
}
