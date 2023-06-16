#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

char board[1005][1005];
int fire_dist[1005][1005];
int j_dist[1005][1005];
queue<pair<int, int> > FQ;
queue<pair<int, int> > Q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    // 거리 초기화
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            fire_dist[i][j] = -1;
            j_dist[i][j] = -1;
        }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'J')
            {
                Q.push(make_pair(i, j));
                board[i][j] = '.';
                j_dist[i][j] = 0;
            }
            else if (board[i][j] == 'F')
            {
                FQ.push(make_pair(i, j));
                fire_dist[i][j] = 0;
            }
        }

    // 불의 확산
    while (!FQ.empty())
    {
        auto cur = FQ.front();
        FQ.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (fire_dist[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;

            fire_dist[nx][ny] = fire_dist[cur.X][cur.Y] + 1;
            FQ.push(make_pair(nx, ny));
        }
    }

    // 지훈이 탈출
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            {
                cout << j_dist[cur.X][cur.Y] + 1;
                return 0;
            }
            if (j_dist[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            if (fire_dist[nx][ny] != -1 && fire_dist[nx][ny] <= j_dist[cur.X][cur.Y] + 1) // 불이 전파된 곳을 확인하는 것이므로 -1(전파되지 않은 곳)은 제외해야 
                continue;

            j_dist[nx][ny] = j_dist[cur.X][cur.Y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
