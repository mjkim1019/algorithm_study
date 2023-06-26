#include <iostream>
#include <algorithm>
using namespace std;

int N;
int board[1001][3];
int d[1001][3]; // i번째 집까지 칠하는 비용의 최솟값, i번째 집은 k로 칠함
int ans = 1000001;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<3; j++)
            cin >> board[i][j];
    }

    for (int k=0; k<3; k++) d[0][k] = board[0][k];
    for (int i=1; i<=N; i++){
        for (int k=0; k<3; k++){
            d[i][k] = min(d[i-1][(k+1)%3], d[i-1][(k+2)%3]) + board[i][k];
        }
    }
    ans = *min_element(d[N], d[N]+3);
    cout << ans;

    return 0;
}
