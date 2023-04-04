/**
 * 1. 함수의 정의
 * 영상 압축 결과 출력
 * void func(int n, int r, int c) // n: 영상크기, (r,c): 시작위치
 * 2. base condition
 * isValid = true
 * 3. 재귀식
 * cout << '(';
 * func(n/2, r + n/2*i, c + n/2*j);
 * cout << ')';
*/

#include <iostream>
using namespace std;

int N;
string board[65];

void func(int n, int r, int c) {
    bool isValid = true;
    for (int i=r; i<r+n; i++){
        for (int j=c; j<c+n; j++){
            if (board[r][c] != board[i][j]){
                isValid = false;
                break;
            }
        }
    }

    if (isValid){
        cout << board[r][c];
    } else {
        cout << '(';
        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++){
                func(n/2, r+n/2*i, c+n/2*j);
            }
        }
        cout << ')';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> board[i];

    func(N, 0, 0);

    return 0;
}
