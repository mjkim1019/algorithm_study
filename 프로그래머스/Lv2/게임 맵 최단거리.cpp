#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dist[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int N = maps.size();
    int M = maps[0].size();
    
    queue<pair<int, int>> Q;
    if (!maps[0][0]) return -1;
    
    dist[0][0] = 1;
    Q.push({0, 0});
    while (!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx<0 || nx >=N || ny<0 || ny >=M) continue;
            if (nx == N-1 && ny == M-1) return dist[cur.X][cur.Y]+1;
            if (maps[nx][ny] == 0 || dist[nx][ny] > 0) continue;
            
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
        }
    }
    
    
    return -1;
}
