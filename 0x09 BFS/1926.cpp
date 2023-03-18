#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int ans = 0;
int cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    // bfs 시작
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] || board[i][j] != 1)
                continue;
            // (i,j)가 시작점
            cnt++;
            int area = 1;
            queue<pair<int, int> > Q;
            vis[i][j] = 1;
            Q.push(make_pair(i, j));
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (vis[nx][ny] || board[nx][ny] != 1)
                        continue;

                    area++;
                    vis[nx][ny] = 1;
                    Q.push(make_pair(nx, ny));
                }
            }
            ans = max(area, ans);
        }
    }
    cout << cnt << '\n'
         << ans;

    return 0;
}
