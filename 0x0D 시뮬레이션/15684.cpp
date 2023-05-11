#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second
#define MAX 0x7f7f7f7f

int N, M, H;
int board[35][15];
vector<pair<int, int> > coords;
int ans = MAX;

bool isComplete;

bool check()
{
    for (int n = 1; n <= N; n++)
    {
        int j = n;
        for (int i = 1; i <= H; i++)
        {
            if (board[i][j] != 0)
                j++;
            else if (board[i][j - 1] != 0)
                j--;
        }
        if (j != n)
            return false;
    }

    return true;
}

void dfs(int L, int vi)
{
    if (ans < L) return;

    if (check())
    {
        ans = min(ans, L);
        return;
    }

    if (L == 3) return;

    for (int i = vi; i<coords.size(); i++){
        auto coord = coords[i];
        if (board[coord.X][coord.Y]) continue;
        board[coord.X][coord.Y] = 2;
        dfs(L + 1, i);
        board[coord.X][coord.Y] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (board[i][j] || board[i][j - 1] || board[i][j + 1])
                continue;
            coords.push_back(make_pair(i, j));
        }
    }

    dfs(0, 0);

    if (ans > 3) cout << "-1";
    else cout <<  ans;

    return 0;
}
