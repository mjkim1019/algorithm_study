#include <iostream>
#include <vector>
using namespace std;

bool board[105][105];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--){
        int x, y, d, g;
        cin >> y >> x >> d >> g;

        vector<int> v;
        v.push_back(d);
        while (g--){
            int size = v.size();
            for (int i=size-1; i>=0; i--){
                v.push_back((v[i]+1)%4);
            }
        }

        board[x][y] = true;
        for (int dir: v){
            x += dx[dir];
            y += dy[dir];
            board[x][y] = true;
        }   
    }

    
    int ans = 0;
    for (int i=0; i<100; i++){
        for (int j=0; j<100; j++){
            if (board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) ans++;
        }
    }
    cout << ans;

    return 0;
}
