#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int N, M;
int board[505][505];

pair<int, int> item[19][4] = {
    {{0,0}, {0,1}, {0,2}, {0,3}}, 
    {{0,0}, {1, 0}, {2,0}, {3,0}}, 

    {{0,0}, {0,1}, {1,0}, {1,1}}, 

    {{0,0}, {1,0}, {2,0}, {2,1}},
    {{0,0}, {1,0}, {0,1}, {0,2}},
    {{2,0}, {0,1}, {1,1}, {2,1}}, 
    {{1,0}, {1,1}, {1,2}, {0,2}}, 
    {{0,0}, {0,1}, {1,0}, {2,0}}, 
    {{0,0}, {1,0}, {1,1}, {1,2}}, 
    {{0,0}, {0,1}, {1,1}, {2,1}},
    {{0,0}, {0,1}, {0,2}, {1,2}}, 
    
    {{0,0}, {1,0}, {1,1}, {2,1}}, 
    {{1,0}, {1,1}, {0,1}, {0,2}}, 
    {{0,1}, {1,1}, {1,0}, {2,0}}, 
    {{0,0}, {0,1}, {1,1}, {1,2}}, 
    
    {{0,0}, {0,1}, {0,2}, {1,1}}, 
    {{1,0}, {0,1}, {1,1}, {2,1}}, 
    {{1,0}, {1,1}, {1,2}, {0,1}}, 
    {{0,0}, {1,0}, {2,0}, {1,1}},
};

int ans = 0;

void check(int num){
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++) {
            int cnt = 0;
            for (int k=0; k<4; k++){
                auto cur = item[num][k];
                if (i+cur.X > N || j+cur.Y > M) {cnt = 0; break;}
                cnt += board[i+cur.X][j+cur.Y];
            }
            ans = max(ans, cnt);
        }
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> board[i][j];
    
    for (int i=0; i<19; i++){
        check(i);
    }

    cout << ans;

    return 0;
}
