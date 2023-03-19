#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int n, m;
int board[1002][1002];
int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > Q;

int ans =0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            if (tmp ==1) {
                Q.push(make_pair(i, j));
            } else if (tmp ==0) {
                dist[i][j] = -1; // 나중에 -1이 남아있으면 다 익지 않은 것을 의미
            }
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx <0 || nx >= n || ny <0 || ny >=m) continue;
            if (dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            Q.push(make_pair(nx, ny));
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int tmp = dist[i][j];
            if (tmp == -1) {
                cout << "-1";
                return 0;
            }
            ans = max(tmp, ans);
        }
    }
    cout << ans;

    return 0;
}
