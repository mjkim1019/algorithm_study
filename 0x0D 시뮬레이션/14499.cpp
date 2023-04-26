#include <iostream>
using namespace std;

int N, M, x, y, K;
int board[25][25];
int dice[7];
//    [1]
// [5][2][6]
//    [3]
//    [4]

int idx[5][4] = {
    {},
    {6,4,5,2}, // 동 : 2->6, 6->4, 4->5, 5->2,
    {5,4,6,2}, // 서 : 2->5, 5->4, 4->6, 6->2
    {1,4,3,2}, // 북 : 2->1, 1->4, 4->3, 3->2
    {1,2,3,4} // 남 : 4->1, 1->2, 2->3, 3->4
};

bool isOk(int nx, int ny){
    if (nx>=0 && nx <N && ny>=0 && ny<M) return true;
    else return false;
}

void roll(int cmd) {
    int tmp[7] = {};
    for (int i=1; i<=6; i++) tmp[i] = dice[i];
    for (int i=0; i<4; i++)
        tmp[idx[cmd][i]] = dice[idx[cmd][(i+1)%4]];
    for (int i=0; i<7; i++) dice[i] = tmp[i];
}

void score(int cmd){
    int nx = x, ny = y;
    if (cmd == 1) // 동
        ny++;
    else if (cmd == 2) // 서
        ny--;
    else if (cmd == 3) // 북
        nx--;
    else // 남
        nx++;

    if (isOk(nx, ny)){
        x = nx, y = ny;
        roll(cmd);

        if (board[x][y] != 0)
        {
            dice[4] = board[x][y];
            board[x][y] = 0;
        }
        else
        {
            board[x][y] = dice[4];
        }
        cout << dice[2] << '\n';
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> x >> y >> K;
    
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
           cin >> board[i][j];
    
    while (K--){
        int cmd;
        cin >> cmd;
        score(cmd);
    }
    

    return 0;
}
