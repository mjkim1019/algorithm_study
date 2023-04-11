#include <iostream>
#define CNT 5
using namespace std;

int N;
int board[22][22];
int origin[22][22];
int ans;

// 90도 회전
void rotate(){
    int tmp[22][22];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            tmp[i][j] = board[i][j];

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            board[i][j] = tmp[N-1-j][i];
}

void tilt(int dir){
    while (dir--) rotate(); // 판 자체를 돌리기

    // 왼쪽으로 기울이기
    for (int i=0; i<N; i++){
        int tilted[22] = {}; // 새 배열
        int idx = 0;
        for (int j=0; j<N; j++){
            if (board[i][j] == 0) continue;

            if (tilted[idx] == 0){
                tilted[idx] = board[i][j];
            } else if (tilted[idx] == board[i][j]){
                tilted[idx++] *= 2;
            } else {
                tilted[++idx] = board[i][j];
            }
        }
        // 다 끝나면 복사해서 board 바꿔주기
        for (int j=0; j<N; j++) board[i][j] = tilted[j];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
    cin >> origin[i][j];


    // 조합
    for (int i=0; i< (1 << 2*CNT); i++){
        // 초기화
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                board[i][j] = origin[i][j];

        int brute = i;
        for (int j=0; j<CNT; j++){
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }

        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                ans = max(ans, board[i][j]);
    }

    cout << ans;

    return 0;
}
