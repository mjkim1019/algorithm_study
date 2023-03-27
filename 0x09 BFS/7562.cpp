#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int T, N;
int x, y;
int wx, wy;

int dist[302][302];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};


int bfs()
{
    queue<pair<int, int> > Q;
    dist[x][y] = 0;
    Q.push(make_pair(x, y));
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 8; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (dist[nx][ny] > -1)
                continue;

            if (nx == wx && ny == wy)
            {
                return dist[cur.X][cur.Y] + 1;
            }

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        for (int i = 0; i < 301; i++)
            fill(dist[i], dist[i] + 301, -1);
        cin >> N;
        cin >> x >> y;
        cin >> wx >> wy;

        cout << bfs() << '\n';
    }

    return 0;
}
