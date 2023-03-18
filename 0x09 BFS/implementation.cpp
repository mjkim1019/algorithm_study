#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int board[502][502] =
    {{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502];
int n= 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<pair<int, int>> Q;
  vis[0][0] = true;
  Q.push({0,0});
  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    for (int i=0; i<4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if (nx <0 || nx >= n || ny <0 || ny >=m) continue;
      if (vis[nx][ny] && board[nx][ny] != 1) continue;

      vis[nx][ny] = 1; 
      Q.push({nx, ny});
    }
  }

  return 0;
}
