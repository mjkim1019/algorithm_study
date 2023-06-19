#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second

using namespace std;

string board[105];
int dist[105][105];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
        fill(dist[i], dist[i]+M, -1);
    }

    dist[0][0] = 1;
    queue<pair<int, int> > Q;
    Q.push(make_pair(0, 0));
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (board[nx][ny] == '0' || dist[nx][ny] >= 0)
                continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }
    cout << dist[N - 1][M - 1];

    return 0;
}
