#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

int N, M, K;
bool board[40][40];
int ans = 0;


bool check(vector<pair<int, int> > pos)
{
    // board에서 가장 위쪽, 왼쪽부터 가능한지 check
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            bool isValid = true;
            for (auto v : pos)
            {
                if (board[i + v.X][j + v.Y] || (i + v.X) >= N || (j + v.Y) >= M)
                {
                    isValid = false;
                    break;
                }
            }

            if (!isValid)
                continue;

            // 스티커 붙이기
            for (auto v : pos)
            {
                board[i + v.X][j + v.Y] = true;
            }
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    while (K--)
    {
        int R, C;
        cin >> R >> C;
        // 스티커 입력
        vector<pair<int, int> > pos;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
            {
                int tmp;
                cin >> tmp;
                if (tmp == 1)
                    pos.push_back(make_pair(i, j));
            }

        for (int dir = 0; dir < 4; dir++)
        {
            if (check(pos))
                break; // 스티커 붙이기 성공
            if (dir == 3)
                break; // 4방향 다 돌려봄

            // 한 방향 다 돌았는데 가능한 경우 없음 -> 회전
            int size;
            if (dir % 2)
                size = C; // 1
            else
                size = R; // 0 2

            for (int i = 0; i < pos.size(); i++)
            {
                int x = pos[i].X;
                pos[i].X = pos[i].Y;
                pos[i].Y = size - 1 - x;
            }

            
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j])
                ans++;
        }
    }
    cout << ans;

    return 0;
}
