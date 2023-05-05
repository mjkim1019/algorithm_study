#include <iostream>
using namespace std;

int N, L;
int board[102][102];
int ans = 0;

// <-, ->, 아래, 위 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void check(){
    bool vis[102][102] = {};
    for (int i = 0; i < N; i++)
    {
        bool isPath = true;
        for (int j = 0; j < N - 1; j++)
        {
            if (board[i][j] == board[i][j + 1])
                continue;

            bool isSlop = true;
            if (board[i][j] + 1 == board[i][j + 1])
            {
                int cnt = 0;
                while (cnt < L)
                {
                    if (vis[i][j-cnt] || board[i][j - cnt] + 1 != board[i][j + 1])
                    {
                        isSlop = false;
                        break;
                    }
                    vis[i][j-cnt] = true;
                    cnt++;
                }
            }
            else if (board[i][j] - 1 == board[i][j + 1])
            {
                int cnt = 0;
                while (cnt++ < L)
                {
                    if (vis[i][j+cnt] || board[i][j] - 1 != board[i][j + cnt])
                    {
                        isSlop = false;
                        break;
                    }
                    vis[i][j+cnt] = true;
                }
            }
            else
                isSlop = false;

            if (!isSlop)
            {
                isPath = false;
                break;
            }
        }

        if (isPath)
        {
            //cout << i << '\n';
            ans++;
        }
    }
}

void rotate(){
    int tmp[102][102];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            tmp[i][j] = board[i][j];

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            board[i][j] = tmp[N-1-j][i];
            //cout << board[i][j]<< ' ';
        }
        // cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> board[i][j];

    // 가로
    check();
    
    // 세로
    rotate();
    check();

    cout << ans;

    return 0;
}
