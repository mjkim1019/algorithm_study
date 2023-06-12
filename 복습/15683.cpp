#include <iostream>
#include <vector>
using namespace std;
#define X first
#define Y second

int N, M;
int board[10][10];
int test[10][10];
int ans;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void upd(int x, int y, int dir){
    dir %= 4;

    while(true){
        x += dx[dir];
        y += dy[dir];
        if (x<0 || x >= N || y <0 || y>= M) break;
        if (board[x][y] == 6) break;
        if (board[x][y] != 0) continue;
        test[x][y] = 7;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    vector<pair<int, int> > cctv;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++){
           cin >> board[i][j];
           if (board[i][j] >=1 && board[i][j] <= 5) cctv.push_back(make_pair(i, j));
           else if (board[i][j] == 0) ans++;
        }

    for (int tmp = 0; tmp< 1 << (2* cctv.size()); tmp++){
        int brute = tmp;

        for (int i = 0; i < N; i++)
           for (int j = 0; j < M; j++)
               test[i][j] = board[i][j];

        for (int i=0; i< cctv.size(); i++){
            int dir = brute % 4;
            brute /= 4;

            auto cur = cctv[i];

            switch (board[cur.X][cur.Y])
            {
            case 1:
                upd(cur.X, cur.Y, dir);
                break;
            case 2:
                upd(cur.X, cur.Y, dir);
                upd(cur.X, cur.Y, dir+2);
                break;
            case 3:
                upd(cur.X, cur.Y, dir);
                upd(cur.X, cur.Y, dir+1);
                break;
            case 4:
                upd(cur.X, cur.Y, dir);
                upd(cur.X, cur.Y, dir+1);
                upd(cur.X, cur.Y, dir+2);
                break;
            case 5:
                upd(cur.X, cur.Y, dir);
                upd(cur.X, cur.Y, dir+1);
                upd(cur.X, cur.Y, dir+2);
                upd(cur.X, cur.Y, dir+3);
                break;
            default:
                break;
            }

            int area = 0;
            for (int k=0; k<N; k++){
                for (int j=0; j<M; j++)
                    if (test[k][j] == 0) area++;
            }
            ans = min(ans, area);
        }
    }

    cout << ans;

    return 0;
}
