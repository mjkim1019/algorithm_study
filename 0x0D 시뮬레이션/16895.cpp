#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 9999
using namespace std;

int board[4][5][5][5];
int maze[5][5][5];
int num[5] = {0, 1, 2, 3, 4};
int freq[5];

int da[6] = {-1, 1, 0, 0, 0, 0};
int db[6] = {0, 0, 1, 0, -1, 0};
int dc[6] = {0, 0, 0, 1, 0, -1};

int ans = MAX;

struct Pos
{
    int a, b, c;
    Pos(int aa, int bb, int cc)
    {
        a = aa;
        b = bb;
        c = cc;
    };
};


bool OOB(int na, int nb, int nc)
{
    if (na >= 0 && na < 5 && nb >= 0 && nb < 5 && nc >= 0 && nc < 5)
        return false;
    return true;
}


int solve(){
    int dist[5][5][5] = {};
    queue<Pos> Q;
    if (maze[0][0][0] == maze[4][4][4] == 0) return MAX;

    Q.push(Pos(0, 0, 0));
    dist[0][0][0] = 1;
    while (!Q.empty())
    {
        Pos cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            int na = cur.a + da[dir];
            int nb = cur.b + db[dir];
            int nc = cur.c + dc[dir];
            if (OOB(na, nb, nc)) continue;
            if (maze[na][nb][nc] == 0) continue;
            if (dist[na][nb][nc] != 0) continue;
            if (na == 4 && nb == 4 && nc == 4)
            {
                return dist[cur.a][cur.b][cur.c];
            }
            Q.push(Pos(na, nb, nc));
            dist[na][nb][nc] = dist[cur.a][cur.b][cur.c] + 1;
        }
    }
    return MAX;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                cin >> board[0][i][j][k];

        // 1번 회전
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[1][i][j][k] = board[0][i][5-1-k][j];

        // 2번 회전
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[2][i][j][k] = board[1][i][5 - 1 - k][j];

        // 3번 회전
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[3][i][j][k] = board[2][i][5 - 1 - k][j];
    }

    do
    {
        for (int i = 0; i < 5; i++)
            freq[i] = num[i]; // 큐브 순서

        for (int tmp = 0; tmp < 1024; tmp++)
        { // 회전 방향 4^5
            int brute = tmp;
            for (int idx = 0; idx < 5; idx++)
            {
                int dir = brute % 4;
                brute /= 4;

               for (int i=0; i<5; i++)
                for (int j=0; j<5; j++){
                    maze[idx][i][j] = board[dir][freq[idx]][i][j]; // 미로 만들기
                }
            }

            // 미로 찾기
           ans = min(solve(), ans);
        }

    } while (next_permutation(num, num + 5));

    if (ans == MAX)
        cout << "-1";
    else
        cout << ans;

    return 0;
}
