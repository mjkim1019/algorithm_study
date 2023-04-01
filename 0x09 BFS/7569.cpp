#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, H;
int board[102][102][102];
int dist[102][102][102];
int dx[6] = {0, 0, 0, -1, 0, 1};
int dy[6] = {0, 0, 1, 0, -1, 0};
int dz[6] = {1, -1, 0,0,0,0};

struct Pos{
    int Z, X, Y;
    Pos(int z, int x, int y){
        Z =z; X = x; Y = y;
    };
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;

    queue<Pos> Q;
    cin >> M >> N >> H;
    for (int k=0; k<H; k++){
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int tmp;
            cin >> tmp;
            board[k][i][j] = tmp;
            if (tmp == 1) {
                Q.push(Pos(k, i, j));
                dist[k][i][j] = 0;
            } else if (tmp == 0) {
                dist[k][i][j] = -1;
            }
        }
    } 
    }

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir=0; dir<6; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            int nz = cur.Z + dz[dir];

            if (nx <0 || nx >=N || ny<0 || ny >= M || nz <0 || nz >=H) continue;
            if (dist[nz][nx][ny] >= 0) continue;

            dist[nz][nx][ny] = dist[cur.Z][cur.X][cur.Y] +1;
            Q.push(Pos(nz, nx, ny));
        }
    }

    for (int k=0; k<H; k++){
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int tmp = dist[k][i][j];
            if (tmp == -1){
                cout << "-1"; return 0;
            }
            ans = max(tmp, ans);
        }
    }
    }
    cout << ans;


    return 0;
}
