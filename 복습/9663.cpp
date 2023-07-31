#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool row[16];
bool dia1[31];
bool dia2[31];
int answer = 0;

void func(int L){
    if (L == N) {
        answer++;
        return;
    }

    for (int j=0; j<N; j++){
        if (!row[j] && !dia1[L+j] && !dia2[L-j+N]){
            row[j] = true;
            dia1[L+j] = true;
            dia2[L-j+N] = true;
            func(L+1);
            row[j] = false;
            dia1[L + j] = false;
            dia2[L - j + N] = false;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N; // 퀸은 모든 방향으로 공격 가능

    func(0);
    cout << answer;

    return 0;
}
