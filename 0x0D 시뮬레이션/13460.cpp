#include <iostream>
#include <queue>
using namespace std;

int N, M;
char board[15][15];
int dist[11][11][11][11];

// <- , -> , 위, 아래
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct Marble
{
    int x, y;
    Marble(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
};
queue<pair<Marble, Marble>> Q;

bool isHole(int x, int y)
{
    return board[x][y] == 'O';
}

Marble move(int dir, int x, int y)
{
    int nx = x, ny = y;
    while (true)
    {
        nx += dx[dir];
        ny += dy[dir];
        if (board[nx][ny] != '.')
            break;
    }
    return Marble(nx - dx[dir], ny - dy[dir]);
}

int bfs()
{
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        Marble R = cur.first;
        Marble B = cur.second;
        int num = dist[R.x][R.y][B.x][B.y];

        if (num >= 10)
            return -1;

        for (int dir = 0; dir < 4; dir++)
        {
            Marble nB = move(dir, B.x, B.y);
            Marble nR = move(dir, R.x, R.y);

            if (isHole(nB.x + dx[dir], nB.y + dy[dir]))
                continue;
            if (isHole(nR.x + dx[dir], nR.y + dy[dir]))
                return num + 1;

            cout << "nR: " << nR.x << ", " << nR.y << '\t';
            cout << "nB: " << nB.x << ", " << nB.y << '\n';

            // 겹쳐진 경우 누가 먼저였는지
            if ((nR.x == nB.x) && (nR.y == nB.y))
            {
                if (dir == 0)
                { // <-
                    R.y < B.y ? nB.y++ : nR.y++;
                }
                else if (dir == 1)
                { // ->
                    R.y > B.y ? nB.y-- : nR.y--;
                }
                else if (dir == 2)
                { // 위
                    R.x < B.x ? nB.x++ : nR.x++;
                }
                else
                { // 아래
                    R.x > B.x ? nB.x-- : nR.x--;
                }
            }

            if (dist[nR.x][nR.y][nB.x][nB.y] != -1)
                continue;
            dist[nR.x][nR.y][nB.x][nB.y] = num + 1;
            Q.push(make_pair(nR, nB));
        }
        cout << '\n';
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int rx, ry, bx, by;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                rx = i;
                ry = j;
                board[i][j] = '.';
            }
            if (board[i][j] == 'B')
            {
                bx = i;
                by = j;
                board[i][j] = '.';
            }
        }

    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
            for (int k = 0; k < 11; k++)
                for (int l = 0; l < 11; l++)
                    dist[i][j][k][l] = -1;

    Q.push(make_pair(Marble(rx, ry), Marble(bx, by)));
    dist[rx][ry][bx][by] = 0;
    cout << bfs();

    return 0;
}
