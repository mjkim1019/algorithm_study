#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int N, M;
int board[10][10];
int test[10][10];
int origin[10][10];
vector<vector<pair<int, int> > > V(6);

int arr[70];

int cnt; // 총 cctv 개수
int min_ans = 64;

void run_c1(int idx, int x, int y);
void run_c2(int idx, int x, int y);
void run_c3(int idx, int x, int y);
void run_c4(int idx, int x, int y);
void run_c5(int x, int y);

void right(int x, int y);
void left(int x, int y);
void up(int x, int y);
void down(int x, int y);

void func(int L)
{
    if (L == cnt)
    {
        copy(&origin[0][0], &origin[0][0] + 100, &test[0][0]); // 초기화

        int k = 0;
        for (auto cur : V[1])
        {
            run_c1(arr[k++], cur.X, cur.Y);
        }
        for (auto cur : V[2])
        {
            run_c2(arr[k++], cur.X, cur.Y);
        }
        for (auto cur : V[3])
        {
            run_c3(arr[k++], cur.X, cur.Y);
        }
        for (auto cur : V[4])
        {
            run_c4(arr[k++], cur.X, cur.Y);
        }
        

        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (!test[i][j])
                    ans++;
            }
        min_ans = min(ans, min_ans);

        return;
    }

    // 0~3 수열 구하기
    for (int i = 0; i < 4; i++)
    {
        arr[L] = i;
        func(L + 1);
    }
}

void run_c1(int idx, int x, int y)
{
    switch (idx)
    {
    case 0:
        right(x, y );
        break;
    case 1:
        down(x, y );
        break;
    case 2:
        left(x, y );
        break;
    case 3:
        up(x, y );
        break;
    default:
        break;
    }
}

void run_c2(int idx, int x, int y)
{
    if (idx == 0 || idx == 1)
    {
        right(x, y );
        left(x, y );
    }
    else
    {
        up(x, y );
        down(x, y );
    }
}

void run_c3(int idx, int x, int y)
{
    switch (idx)
    {
    case 0:
        up(x, y );
        right(x, y );
        break;
    case 1:
        right(x, y );
        down(x, y );
        break;
    case 2:
        down(x, y );
        left(x, y );
        break;
    case 3:
        left(x, y );
        up(x, y );
        break;

    default:
        break;
    }
}

void run_c4(int idx, int x, int y)
{
    switch (idx)
    {
    case 0:
        left(x, y );
        up(x, y );
        right(x, y );
        break;
    case 1:
        up(x, y );
        right(x, y );
        down(x, y );
        break;
    case 2:
        left(x, y );
        right(x, y );
        down(x, y );
        break;
    case 3:
        up(x, y );
        down(x, y );
        left(x, y );
        break;

    default:
        break;
    }
}

void run_c5(int x, int y)
{
    right(x, y );
    left(x, y );
    up(x, y );
    down(x, y );
}

void right(int bX, int bY )
{
    if (bY == M - 1)
        return;
    for (int j = bY + 1; j < M; j++)
    {
        if (board[bX][j] == 6)
            break;
        test[bX][j] = true;
    }
}

void left(int bX, int bY )
{
    if (bY == 0)
        return;
    for (int j = bY - 1; j >= 0; j--)
    {
        if (board[bX][j] == 6)
            break;
        test[bX][j] = true;
    }
}

void up(int bX, int bY )
{
    if (bX == 0)
        return;
    for (int i = bX - 1; i >= 0; i--)
    {
        if (board[i][bY] == 6)
            break;
        test[i][bY] = true;
    }
}

void down(int bX, int bY )
{
    if (bX == N - 1)
        return;
    for (int i = bX + 1; i < N; i++)
    {
        if (board[i][bY] == 6)
            break;
        test[i][bY] = true;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            if (tmp != 0)
            {
                test[i][j] = true;
                if (tmp != 6)
                {
                    V[tmp].push_back(make_pair(i, j));
                    cnt++;
                }
            }
        }
    }

    for (auto cur : V[5])
    {
        run_c5(cur.X, cur.Y);
    }
    copy(&test[0][0], &test[0][0]+100, &origin[0][0]);

    func(0);
    cout << min_ans;

    return 0;
}
