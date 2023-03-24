#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int m, n, k;
int ans = 0;
int board[52][52];
bool vis[52][52];

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push(make_pair(x, y));
    vis[x][y] = true;

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (vis[nx][ny] || board[nx][ny] != 1)
                continue;
            vis[nx][ny] = true;
            Q.push(make_pair(nx, ny));
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> m >> n >> k;
        
        for (int i=0; i<52; i++) {
            fill(board[i], board[i]+52, 0);
            fill(vis[i], vis[i]+52, false);
        }
        ans = 0;

        while(k--){
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] != 1 || vis[i][j]) continue;
                bfs(i, j);
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
