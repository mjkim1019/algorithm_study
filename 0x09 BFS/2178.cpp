#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define X first
#define Y second

string board[102];  // 미로
int dist[102][102]; // 거리 계산을 위한 배열
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1); // dist 배열 -1로 초기화

    queue<pair<int, int> > Q;
    dist[0][0] = 1;
    Q.push(make_pair(0, 0));
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
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
                continue; // dist >= 0이면 이미 방문한 곳
            int ndist = dist[cur.X][cur.Y] + 1;
            dist[nx][ny] = ndist;
            Q.push(make_pair(nx, ny));
        }
    }
    cout << dist[n - 1][m - 1];

    return 0;
}
