#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int M, N;
int box[1001][1001];
int dist[1001][1001];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int> > Q;
    cin >> M >> N;
    for (int i = 0; i < N; i++)
        fill(dist[i], dist[i] + M, -1);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
            { // 익은 토마토
                dist[i][j] = 0;
                Q.push(make_pair(i, j));
            }
            if (box[i][j] == -1) dist[i][j] = 0;
        }
    }

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = dx[dir] + cur.X;
            int ny = dy[dir] + cur.Y;

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (box[nx][ny] != 0 || dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }

    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (dist[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;

    return 0;
}
