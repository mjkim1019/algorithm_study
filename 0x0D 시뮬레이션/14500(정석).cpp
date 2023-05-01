#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int N, M;
int board[505][505];

int ans = 0;
vector<vector<pair<int, int> > > tetro;

bool isAdj(pair<int, int> s1, pair<int, int> s2)
{
    if (s1.X == s2.X)
        return abs(s1.Y - s2.Y) == 1;
    else if (s1.Y == s2.Y)
        return abs(s1.X - s2.X) == 1;

    return false;
}

// 4개의 칸이 연결되어 있는지 확인하는 함수
bool isConn(vector<pair<int, int> > &shape)
{
    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        int cnt = 0; // 인접한 칸의 개수
        for (int j = 0; j < 4; j++)
        {
            if (isAdj(shape[i], shape[j]))
                cnt++;
        }
        if (cnt >= 2)
            flag = true;
        if (cnt == 0)
            return false;
    }

    return flag;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    vector<int> brute(16);
    fill(brute.begin() + 12, brute.end(), 1); // 4개만 1로
    do
    {
        vector<pair<int, int> > shape;
        for (int i = 0; i < 16; i++)
        {
            if (brute[i] == 1)
                shape.push_back(make_pair(i / 4, i % 4));
        }
        if (isConn(shape))
            tetro.push_back(shape);
    } while (next_permutation(brute.begin(), brute.end()));

    for (int i = 0; i <= N - 4; i++)
    {
        for (int j = 0; j <= M - 4; j++)
        {
            for (auto shape : tetro)
            {
                int sum = 0;
                for (auto coor : shape)
                {
                    sum += board[i + coor.X][j + coor.Y];
                }
                ans = max(ans, sum);
            }
        }
    }

    cout << ans;

    return 0;
}
