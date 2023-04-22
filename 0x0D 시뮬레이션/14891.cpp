#include <iostream>
#include <algorithm>
using namespace std;

int k; // 회전 횟수
string wheel[4];

void go(int x, int dir){
    int dirs[4] = {};
    dirs[x] = dir;
    // 왼쪽으로 회전을 전파
    int idx = x;
    while (idx > 0 && wheel[idx][6] != wheel[idx - 1][2])
    {
        dirs[idx - 1] = -dirs[idx];
        idx--;
    }

    // 오른쪽으로 회전을 전파
    idx = x;
    while (idx < 3 && wheel[idx][2] != wheel[idx + 1][6])
    {
        dirs[idx + 1] = -dirs[idx];
        idx++;
    }

    for (int i = 0; i < 4; i++)
    {
        if (dirs[i] == -1)
            rotate(wheel[i].begin(), wheel[i].begin() + 1, wheel[i].end());
        else if (dirs[i] == 1)
            rotate(wheel[i].begin(), wheel[i].begin() + 7, wheel[i].end());
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i=0; i<4; i++)
        cin >> wheel[i];

    cin >> k;
    while (k--){
        int num, dir;
        cin >> num >> dir;
        
        go(num-1, dir);
    }

    int ans = 0;
    for (int i=0; i<4; i++){
        if (wheel[i][0] == '1') ans += (1<<i);
    }
    cout << ans;
   

    return 0;
}
