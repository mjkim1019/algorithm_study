#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#define X first
#define Y second
using namespace std;

int N;
int board[105][105];
queue<pair<int, char> > Q;    // 뱀의 방향 정보
deque<pair<int, int> > snake; // 뱀의 위치
int direction;               // 0:동 1:남 2:서 3:북

// 동 남 서 북
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, L;
    cin >> N >> K;
    while (K--)
    {
        int a, b;
        cin >> a >> b;
        board[a][b] = 2;
    }
    cin >> L;
    while (L--)
    {
        int t;
        char c;
        cin >> t >> c;
        Q.push(make_pair(t, c));
    }

    int ans = 0;
    snake.push_back(make_pair(1, 1));
    direction = 0;
    while (true)
    {
        ans++;

        auto cur = snake.front();
        board[cur.X][cur.Y] = 1;

        int nx = cur.X + dx[direction];
        int ny = cur.Y + dy[direction];
        if (nx < 1 || nx > N || ny < 1 || ny > N) break;
        if (board[nx][ny] == 1) break;

        if (board[nx][ny] != 2)
        {
            auto tail = snake.back();
            board[tail.X][tail.Y] = 0;
            snake.pop_back();
        }

        auto sd = Q.front();
        if (sd.X == ans)
        {
            if (sd.Y == 'L')
            { // 왼쪽 회전
                direction = (direction + 3) % 4;
            }
            else if (sd.Y == 'D')
            { // 오른쪽 회전
                direction = (direction + 1) % 4;
            }
            Q.pop();
        }

        snake.push_front(make_pair(nx, ny));
    }

    cout << ans;

    return 0;
}
