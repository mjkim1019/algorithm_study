#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define X first
#define Y second

int ans;
int N, M;
int board[10][10];
int test[10][10];
vector<pair<int, int> > cctv;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void rotate(int dir, int x, int y){
    dir %= 4;
    while (true){
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x>= N || y<0 || y>=M) break;
        if (test[x][y] == 6) break;
        if (test[x][y] != 0) continue;
        test[x][y] = 7;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    ans = N*M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++){
            cin >> board[i][j];
            if (board[i][j] >=1 && board[i][j] <=5) cctv.push_back(make_pair(i, j));
        }

    for (int brute = 0; brute < (1 << 2*cctv.size()); brute++)
    {
        // test 초기화
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                test[i][j] = board[i][j];

        int tmp = brute;
        for (int k= 0; k< cctv.size(); k++){
            int dir = tmp %4;
            tmp /= 4;
            //cout << dir <<' ';
            // cctv 하나씩 동작
            switch (board[cctv[k].X][cctv[k].Y])
            {
            case 1:
                rotate(dir, cctv[k].X, cctv[k].Y);
                break;
            case 2:
                rotate(dir, cctv[k].X, cctv[k].Y);
                rotate(dir + 2, cctv[k].X, cctv[k].Y);
                break;
            case 3:
                rotate(dir, cctv[k].X, cctv[k].Y);
                rotate(dir + 3, cctv[k].X, cctv[k].Y);
                break;
            case 4:
                rotate(dir, cctv[k].X, cctv[k].Y);
                rotate(dir + 2, cctv[k].X, cctv[k].Y);
                rotate(dir + 3, cctv[k].X, cctv[k].Y);
                break;
            case 5:
                rotate(dir, cctv[k].X, cctv[k].Y);
                rotate(dir + 1, cctv[k].X, cctv[k].Y);
                rotate(dir + 2, cctv[k].X, cctv[k].Y);
                rotate(dir + 3, cctv[k].X, cctv[k].Y);
                break;
            
            default:
                break;
            }
        }
        //cout << '\n';
        // 사각지대 크기 계산
        int res = 0;
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                if (test[i][j] == 0) res++;
            
        
        ans = min(ans, res);
    }
    
    cout << ans;

    return 0;
}
