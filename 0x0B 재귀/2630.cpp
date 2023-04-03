/**
 * 1. 함수의 정의
 * void func(int n, int r, int c)
 * 2. base condition
 * 전부 파란색 or 하얀색 -> return
 * 3. 재귀식
 * func(n/2, r + n/2*i, n/2*j) (2번)
*/

#include <iostream>
using namespace std;

int N;
int board[150][150];
int ans[2];

void func(int n, int r, int c) {
    bool isValid = true;
    for (int i=r; i<r+n; i++){
        for (int j=c; j<c+n; j++){
            if (board[i][j] != board[r][c]) {
                isValid = false;
                break;
            }
        }
    }

    if (isValid) {
        ans[board[r][c]]++;
    } else {
        int half = n/2;
        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++){
                func(half, r+half*i, c+half*j);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }
    func(N, 0, 0);
    
    for (int i: ans){
        cout << i << '\n';
    }

    return 0;
}
