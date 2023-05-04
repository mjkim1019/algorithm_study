#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int N, M;
int board[10][10];
int test[10][10];
vector<pair<int, int> > virus;
int ans = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void cal(){
    int res = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (test[i][j] == 0) res++;
    ans = max(ans, res);
}

void bfs(){
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            test[i][j] = board[i][j];
    int vis[10][10]= {};
    queue<pair<int, int> > Q;
    for (auto &v: virus){
        Q.push(v);
        vis[v.X][v.Y] = true;
    }
    while (!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir<4; dir++){
            int nx = cur.X+ dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx<0 || nx >= N || ny <0 || ny >= M) continue;
            if (test[nx][ny] != 0) continue;
            if (vis[nx][ny]) continue;
            
            test[nx][ny] = 2;
            vis[nx][ny] = true;
            Q.push(make_pair(nx, ny));
        }
    }

    cal();
}

void dfs(int L){
    if (L == 3){
        bfs();
        return;
    }

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++){
            if (board[i][j] != 0) continue;
            board[i][j] = 1;
            dfs(L+1);
            board[i][j] = 0;
        }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++){
            cin >> board[i][j];
            if (board[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
        }
    
    dfs(0);
    cout << ans;

    return 0;
}
