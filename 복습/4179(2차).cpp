#include <iostream>
#include <queue>
#include <string>
#define X first
#define Y second
using namespace std;

int R, C;
string board[1001];
queue<pair<int, int> > FQ;
queue<pair<int, int> > JQ;
int Fdist[1001][1001];
int Jdist[1001][1001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(0);   
    cin.tie(0);

    cin >> R >> C;

    for (int i=0; i<R; i++)
        cin >> board[i];

    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++){
            Fdist[i][j] = -1;
            Jdist[i][j] = -1;

            if (board[i][j] == 'J'){
                JQ.push(make_pair(i, j));
                board[i][j] = '.';
                Jdist[i][j] = 0;
            }
            else if (board[i][j] == 'F'){
                FQ.push(make_pair(i, j));
                Fdist[i][j] = 0;
            }
        }

    // 불의 전파
    while (!FQ.empty()){
        auto cur = FQ.front(); FQ.pop();

        for (int dir = 0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (Fdist[nx][ny] != -1 || board[nx][ny] == '#') continue;

            Fdist[nx][ny] = Fdist[cur.X][cur.Y]+1;
            FQ.push(make_pair(nx, ny));
        }
    }

    while (!JQ.empty()){
        auto cur = JQ.front(); JQ.pop();

        for (int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) { // 탈출 성공
                cout << Jdist[cur.X][cur.Y]+1;
                return 0;
            }

            if (Jdist[nx][ny] != -1 || board[nx][ny] == '#') continue;
            if (Fdist[nx][ny] != -1 && Fdist[nx][ny] <= Jdist[cur.X][cur.Y]+1) continue;

            Jdist[nx][ny] = Jdist[cur.X][cur.Y]+1;
            JQ.push(make_pair(nx, ny));
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
