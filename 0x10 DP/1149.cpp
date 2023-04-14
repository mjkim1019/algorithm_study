#include <iostream>
#include <algorithm>
using namespace std;

int s[1002][3];
int d[1002][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> s[i][0] >> s[i][1] >> s[i][2];
    }

    // 초기값
    for (int k=0; k<3; k++) d[1][k] = s[1][k];

    for (int i=2; i<=N; i++){
        for (int k=0; k<3; k++){
            d[i][k] = s[i][k] + min(d[i - 1][(k + 1) % 3], d[i - 1][(k + 2) % 3]);
        }
    }

    int ans = *min_element(d[N], d[N]+3);
    
    cout << ans;

    return 0;
}
