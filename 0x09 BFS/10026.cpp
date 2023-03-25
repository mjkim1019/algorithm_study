  #include <iostream>
#include <queue>
#include <string>
#define X first
#define Y second
using namespace std;

int N;
string board[102];
bool vis1[102][102];
bool vis2[102][102];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1, 0, 1};
int ans[2];

void bfs(bool vis[102][102], int i, int j, bool isWeak) {
    queue<pair<int, int> > Q;
    vis[i][j] = true;
    Q.push(make_pair(i, j));
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        char c = board[cur.X][cur.Y];
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (vis[nx][ny]) continue;
            if (isWeak) {
                if (c == board[nx][ny] || (c + board[nx][ny] == 'R' + 'G'))
                {
                    vis2[nx][ny] = true;
                    Q.push(make_pair(nx, ny));
                }
            } else {
                if (board[nx][ny] != c) continue;
                vis[nx][ny] = true;
                Q.push(make_pair(nx, ny));
            }
            
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> board[i];
    }

    
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++) {
            if (!vis1[i][j]) {
                bfs(vis1, i, j, false);
                ans[0]++;
            }

            if (!vis2[i][j]) {
                bfs(vis2, i, j, true);
                ans[1]++;
            }
        }
    }

    cout << ans[0] << ' ' << ans[1];

    
    return 0;
}
