#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define N 12
#define M 6
using namespace std;

char board[15][10];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans = 0;

struct Pos
{
    int x, y;
    char color;
    Pos(char c, int xx, int yy)
    {
        color = c;
        x = xx;
        y = yy;
    }
};

void print()
{
    cout << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    while (true)
    {
        bool isBomb = false;

        bool vis[15][10] ={};
        // 터지는 부분 check
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == '.')
                    continue;
                queue<Pos> Q;
                Q.push(Pos(board[i][j], i, j));
                vis[i][j] = true;

                vector<pair<int, int> > v;
                v.push_back(make_pair(i, j));
                while (!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;
                        if (vis[nx][ny])
                            continue;

                        if (cur.color == board[nx][ny])
                        {
                            vis[nx][ny] = true;
                            Q.push(Pos(board[i][j], nx, ny));
                            v.push_back(make_pair(nx, ny));
                        }
                    }
                }

                // 터질 수 있는가 check
                if (v.size() < 4)
                    continue;
                // 터지면 .으로 만들기
                for (auto cur : v)
                {
                    board[cur.first][cur.second] = '.';
                    isBomb = true;
                }
            }
        }

        if (!isBomb) break;

        // 아래로 당기기
        char tmp[15][10];
        for (int i = 0; i < 15; i++)
            fill(tmp[i], tmp[i] + 10, '.');

        for (int j = 0; j < M; j++)
        {
            int idx = N - 1;
            for (int i = N - 1; i >= 0; i--)
            {
                if (board[i][j] == '.')
                    continue;
                tmp[idx--][j] = board[i][j];
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                board[i][j] = tmp[i][j];
            }
        }

        //print();
        ans++;
    }
    cout << ans;

    return 0;
}
