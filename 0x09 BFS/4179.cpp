#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int r, c;
string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int jx, jy;
    queue<pair<int, int> > Q;

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> board[i];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char tmp = board[i][j];
            if (tmp == 'J')
            {
                jx = i; jy = j;
                dist2[i][j] = 0;
            }
            else if (tmp == 'F')
            {
                Q.push(make_pair(i, j));
                dist1[i][j] = 0;
            } else {
            dist1[i][j] = -1;
            dist2[i][j] = -1;
            }
        }
    }

    // 불의 전파
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }

    // 지훈이의 이동
    Q.push(make_pair(jx, jy));
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
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') // J가 이동함에 따라 board에서 J의 위치도 갈 수 있으므로
                continue;
            if (dist1[nx][ny] != -1 && dist2[cur.X][cur.Y] + 1 >= dist1[nx][ny]) // dist1 벽은 볼 필요 X
                continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}
