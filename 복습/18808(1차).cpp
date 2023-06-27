#include <iostream>
using namespace std;

int N, M, K;
int w, h;
int sticker[11][11];
int board[45][45];

void init_sticker(){
    for (int i=0; i<11; i++)
        for (int j=0; j<11; j++)
            sticker[i][j] = 0;
}

bool check(int x, int y){
    for (int i=0; i<w; i++){
        for (int j=0; j<h; j++){
            if (board[x+i][y+j] == 1 && sticker[i][j] == 1) 
                return false; // 이미 스티커 붙어있음
        }
    }

    for (int i=0; i<w; i++){
        for (int j=0; j<h; j++){
            if (sticker[i][j] == 1)
                board[x+i][y+j] = sticker[i][j];
        }
    }

    return true;
}


void rotate(){
    int nsticker[11][11];
    for (int i=0; i<w; i++)
        for (int j=0; j<h; j++)
            nsticker[i][j] = sticker[i][j];
    
    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++)
            sticker[i][j] = nsticker[w-1-j][i];
    swap(w, h);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    while (K--){
        cin >> w >> h;
        init_sticker();
        for (int i=0; i<w; i++)
            for (int j=0; j<h; j++)
                cin >> sticker[i][j];

        for (int dir=0; dir<4; dir++){
            bool is_paste = false;
            for (int i=0; i<= N-w; i++){
                if (is_paste) break;
                for (int j=0; j<= M-h; j++){
                    if (check(i, j)) {is_paste = true; break;}
                }
            }
            if (is_paste) break;
            rotate();
        }
    }

    int ans = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (board[i][j] == 1) ans++;
    cout << ans;

    return 0;
}
