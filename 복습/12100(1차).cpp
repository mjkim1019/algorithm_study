#include <iostream>
using namespace std;

int board[21][21];
int origin[21][21];
int N;

void rotate(){
    int tmp[21][21] = {};
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            tmp[i][j] = board[i][j];
        
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            board[i][j] = tmp[N-1-j][i];
}

void tilt(int dir){
    while(dir--) rotate(); // 판 돌리기
    
    // 왼쪽으로 기울이기
    for (int i=0; i<N; i++){
        int tilted[21] = {};
        int idx = 0;
        for (int j=0; j<N; j++){
            if (board[i][j] == 0) continue;

            if (tilted[idx] == 0) // 비어있으면
                tilted[idx] = board[i][j];
            else if (tilted[idx] == board[i][j])
                tilted[idx++] *= 2;
            else 
                tilted[++idx] = board[i][j];
        }
        for (int j=0; j<N; j++) board[i][j] = tilted[j];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    cin >> N;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> origin[i][j];

    for (int i=0; i< 1<<2*5; i++){
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                board[i][j] = origin[i][j];

        int brute = i;
        for (int j=0; j<5; j++){
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
