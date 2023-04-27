#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[55][55];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Pos{
    int x, y;
    int dir; // 0: 북, 1: 동, 2: 남, 3: 서
    Pos(int xx, int yy, int d){
        x = xx; y = yy; dir = d;
    }
};

bool OOB(int nx, int ny){ // Out Of Bound
    if (nx >=0 && nx <N && ny >=0 && ny<M) return false;
    return true;
}

bool check(int x, int y){
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (OOB(nx, ny)) continue;
        if (board[nx][ny] == 0) return true; 
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int a, b, c;
    cin >> a >> b >> c;

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> board[i][j];
    

    queue<Pos> Q;
    Q.push(Pos(a, b, c));
    board[a][b] = 2;
    while(!Q.empty()) {
        Pos cur = Q.front(); Q.pop();
        
        if (check(cur.x, cur.y)){ // 주변 4칸 중 빈칸 O
            int dir = (cur.dir+3) % 4;
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (OOB(nx, ny)) continue;
            if (board[nx][ny] == 0){ // 회전 후 앞으로 이동
                Q.push(Pos(nx, ny, dir));
                board[nx][ny] = 2;
            } else { // 이동없이 회전만
                Q.push(Pos(cur.x, cur.y, dir));
            }
        } else { // 주변 4칸 중 빈칸 X
            int rdir = (cur.dir+2) % 4;
            int nx = cur.x + dx[rdir];
            int ny = cur.y + dy[rdir];
            if (OOB(nx, ny)) continue;
            if (board[nx][ny] == 1) break;
            else { // 0 or 2
                Q.push(Pos(nx, ny, cur.dir));
                board[nx][ny] = 2;
            }
        }
    }

    int ans = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (board[i][j] == 2) ans++;
        }
    }
    
    cout << ans;

    return 0;
}
