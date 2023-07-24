#include <iostream>
using namespace std;

int N, M, K;
int R, C;
int board[41][41];
int sticker[11][11];

bool paste_sticker(int x, int y){
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            if (sticker[i][j] && board[x + i][y + j]) return false;
        }
    }

    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            if (sticker[i][j]) board[x+i][y+j] = 1;
        }
    }

    return true;
}

bool is_pastable(){
    for (int i=0; i<=N-R; i++){
        for (int j=0; j<= M-C; j++){
            if (paste_sticker(i, j)) return true;
        }
    }
    return false;
}

void rotate(){
    int nsticker[11][11] ={};
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
    
    while (K--){
        cin >> R >> C;
        for (int i=0; i<R; i++)
            for (int j=0; j<C; j++)
                cin >> sticker[i][j];
        
        for (int dir=0; dir<4; dir++){
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
