#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second

int N, M;
int board[505][505];
bool vis[505][505];
int ans = 0;
int cnt = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0 || vis[i][j])
                continue;
            
            cnt++;
            int area = 0;
            queue<pair<int, int> > Q;
            Q.push(make_pair(i, j));
            vis[i][j] = true;
            while (!Q.empty())
            {
                auto cur = Q.front();Q.pop();
                area++;
                //cout << area << ": " << cur.X << ", " << cur.Y << '\n';

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                        continue;
                    if (vis[nx][ny] || board[nx][ny] == 0)
                        continue;

                    Q.push(make_pair(nx, ny));
                    vis[nx][ny] = true;
                }
            }
            ans = max(ans, area);
        }
    }
    cout << cnt << '\n' << ans;

    return 0;
}
