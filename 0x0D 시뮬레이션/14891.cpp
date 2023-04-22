#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

deque<int> wheel[5]; // 1,2,3,4 사용
int k; // 회전 횟수
int stnum;
int ennum;
bool visited[5];

int reverseDir(int dir){
    if (dir > 0)
        return -1;
    else
        return 1;
}

void rotate(int num, int dir){
    if (dir == 1) { // 시계 방향
        int value = wheel[num].back();
        wheel[num].pop_back();
        wheel[num].push_front(value);
    } else { // 반시계 방향
        int value = wheel[num].front();
        wheel[num].pop_front();
        wheel[num].push_back(value);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input[5];
    for (int i=1; i<=4; i++)
        cin >> input[i];
    for (int i=1; i<=4; i++)
        for (int j=0; j<8; j++)
            wheel[i].push_back(input[i][j]-'0');
    
    cin >> k;
    while (k--){
        int num, dir;
        cin >> num >> dir;
        
        queue<pair<int, int> > Q;
        fill(visited, visited+5, false);
        Q.push(make_pair(num, dir));
        visited[num] = true;
        while (!Q.empty()){
            auto cur = Q.front(); Q.pop();
            int num = cur.first;
            int dir = cur.second;
            //cout << '\n' << num << ", " << dir << '\n';

            // 오른쪽 확인
            if (num < 4 && !visited[num+1] && wheel[num].at(2) != wheel[num + 1].at(6)) {
                Q.push(make_pair(num + 1, reverseDir(dir)));
                visited[num+1] = true;
            }
            // 왼쪽 확인
            if (num > 1 && !visited[num-1] && wheel[num].at(6) != wheel[num-1].at(2)) {
                Q.push(make_pair(num - 1, reverseDir(dir)));
                visited[num-1] = true;
            }

            // dir 방향으로 회전
            rotate(num, dir);
        }

    }

    int ans = 0;
    for (int i=1; i<=4; i++){
        if (wheel[i].front() == 1) ans += 1<<(i-1);
    }
    cout << ans;

    return 0;
}
