/**
 * 1. 함수의 정의
 * void func(int n, int r, int c) // (r,c) 시작점
 * 2. base condition
 * 구역 다 check했을 때 true
 * 3. 재귀식
 * func(n/3, r+(n/3)*i, r+(n/3)*j)
*/

#include <iostream>
using namespace std;

int N;
int board[2200][2200];
int ans[3]; // -1, 0, 1

void func(int n, int r, int c) {
    bool isPass = true;
    int num = board[r][c];
    for (int i=r; i<n+r; i++){
        for (int j=c; j<n+c; j++) {
            if (board[i][j] != num){
                isPass = false;
                break;
            }
        }
    }
    if (isPass) ans[num+1]++;
    else {
        int nxt = n/3;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                func(nxt, r + nxt * i, c + nxt * j);
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0; i< N; i++){
        for (int j=0; j < N; j++){
            cin >> board[i][j];
        }
    }
    
    func(N, 0, 0);
    
    for (int cnt: ans){
        cout << cnt << '\n';
    }

    return 0;
}
