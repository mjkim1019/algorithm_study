#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
pair<int, int> pos;
string board[50];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0}; // 동 서 남 북

bool OOB(pair<int, int> &pos, int N, int M){
    if (pos.X < 0 || pos.X >=N || pos.Y < 0 || pos.Y >= M) return true;
    return false;
}

void move(char direction, int cnt, vector<string>& park){
    int dir = -1;
    if (direction == 'E') dir = 0;
    else if (direction == 'W') dir = 1;
    else if (direction == 'S') dir = 2;
    else if (direction == 'N') dir = 3;
    
    pair<int, int> npos = pos;
    while (cnt--){
        npos.X += dx[dir];
        npos.Y += dy[dir];
        if (OOB(npos, park.size(), park[0].size())) break;
        if (park[npos.X][npos.Y] == 'X') break;
    }
    
    if (cnt < 0) pos = npos;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2);
    
    for (int i=0; i<park.size(); i++)
        for (int j=0; j<park[i].size(); j++)
            if (park[i][j] == 'S') pos = {i, j};

    for (string route: routes){
        move(route[0], route[2]-'0', park);
    }
    answer[0] = pos.X;
    answer[1] = pos.Y;
    
    return answer;
}
