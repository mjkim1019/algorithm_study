#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[45][45];
int sticker[15][15];
int R, C;
int N, M, K;

void init_sticker(){
    for (int i=0; i<15; i++) fill(sticker[i], sticker[i]+15, 0);
}

bool check(int x, int y){
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (sticker[i][j]==1 && board[i+x][j+y]==1) return false;
        }
    }

    // 가능하면 스티커 붙이기
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
           if (sticker[i][j] == 1) board[i+x][j+y] = 1;
        }
    }

    return true;
}

bool isFound(){
    for (int i = 0; i <= N-R; i++)
    {
        for (int j = 0; j <= M-C; j++)
        {
            if (check(i, j)) return true;
        }
    }
    return false;
}

void rotate(){
    int tmp[15][15];
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
            tmp[i][j] = sticker[i][j];

    for (int i=0; i<C; i++)
        for (int j=0; j<R; j++)
            sticker[i][j] = tmp[R-j-1][i];

    swap(R, C);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    while (K--){
        init_sticker();
        cin >> R >> C;
        for (int i=0; i<R; i++)
            for (int j=0; j<C; j++)
                cin >> sticker[i][j];

        for (int dir=0; dir<4; dir++){
            if (isFound()) break;
            rotate();
        }
    }

    int ans = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) 
            ans += board[i][j];
    cout << ans;

    return 0;
}
