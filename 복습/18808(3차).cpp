#include <iostream>
using namespace std;

int N, M, K;
int R, C;
int board[41][41];
int sticker[11][11];

bool paste(int x, int y){
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            if (sticker[i][j]==1 && board[x+i][y+j]==1) return false;
        }
    }

    for (int i=0; i<R; i++)
        for (int j=0;j <C; j++)
            if (sticker[i][j]) board[x+i][y+j] = 1;
    return true;
}

bool is_pastable(){
    for (int i=0; i<=N-R; i++){
        for (int j=0; j<=M-C; j++){
            if (paste(i, j)) return true;
        }
    }
    return false;
}

void rotate(){
    int nsticker[11][11] = {};
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
            nsticker[i][j] = sticker[i][j];

    for (int i=0; i<C; i++)
        for (int j=0; j<R; j++)
            sticker[i][j] = nsticker[R-1-j][i];
    swap(R, C);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    // 1. 스티커 붙일 수 있나 확인하기 -> 가능하면 붙이기 & 다음 스티커 차례
    // 2. 스티커 90도 회전시키고 1번 과정 진행
    // 3. 스티커 90도, 180도, 270도 회전
    // 4. 붙일 곳 없으면 스티커 버리기

    while (K--){
        cin >> R >> C;
        for (int i=0; i<R; i++)
            for (int j=0; j<C; j++)
                cin >> sticker[i][j];

        for (int dir = 0; dir<4; dir++){
            if (is_pastable()) break;
            rotate();
        }   
    }
    
    int answer = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            answer += board[i][j];
    cout << answer;

    return 0;
}
