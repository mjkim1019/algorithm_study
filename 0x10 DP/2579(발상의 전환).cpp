#include <iostream>
#include <algorithm>
using namespace std;

int s[302];
int d[302]; // i번째에 올라섰을 때 밟지 않은 계단의 점수 최소합, 단 i번째 계단은 밟지 않는다

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int N;
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> s[i];
        sum += s[i];
    }

    if (N <= 2){
        cout << sum;
        return 0;
    }

    d[1]= s[1]; d[2]= s[2]; d[3]=s[3];
    for (int i=4; i<N; i++){
        d[i] = min(d[i-2], d[i-3]) + s[i];
    }
    
    int ans;
    ans = sum - min(d[N-1], d[N-2]);
    cout << ans;

    return 0;
}
