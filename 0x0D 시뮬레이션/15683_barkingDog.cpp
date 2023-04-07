#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

int N, M;
int board[10][10];
int test[10][10];
vector<pair<int, int> > cctv;
int min_ans;
// 서 남 동 북
int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {1, 0, -1, 0};

// Out Of Bound
bool OOB(int x, int y){
    return (x <0 || x>= N || y<0 || y>=M);
}

void upd(int x, int y, int dir){
    dir %= 4;
    while (true){
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y) || board[x][y] == 6) return;
        if (board[x][y] != 0) continue;
        test[x][y] = 7;
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
            if (tmp != 0 && tmp != 6)
                cctv.push_back(make_pair(i, j));
            if (tmp == 0)
                min_ans++;
        }
    }

    // 1. 진법 계산을 통한 조합
    for (int tmp = 0; tmp < (1 << 2 * cctv.size()); tmp++)
    {
        // 초기화
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                test[i][j] = board[i][j];

        int brute = tmp;
        for (int i = 0; i < cctv.size(); i++)
        {
            int dir = brute % 4;
            brute /= 4;

            int x = cctv[i].X;
            int y = cctv[i].Y;

            switch (board[x][y])
            {
            case 1:
                upd(x, y, dir);
                break;
            case 2:
                upd(x, y, dir);
                upd(x, y, dir+2);
                break;
            case 3:
                upd(x, y, dir);
                upd(x, y, dir+1);
                break;
            case 4:
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                break;
            case 5:
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
                break;

            default:
                break;
            }
        }

        // 면적 계산
        int ans = 0;
        for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
        if (test[i][j] == 0) ans++;
        min_ans = min(ans, min_ans);
    }

    cout << min_ans;


    return 0;
}
