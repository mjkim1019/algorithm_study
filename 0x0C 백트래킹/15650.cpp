#include <iostream>
using namespace std;

int N, M;

bool isUsed[10];
int ans[10];

void func(int L){
    if (L == M){
        for (int i=0; i<M; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    int start = 1;
    if (L != 0) start = ans[L-1]+1;
    for (int i= start; i<=N; i++){
        if (!isUsed[i]) {
            isUsed[i] = true;
            ans[L] = i;
            func(L+1);
            isUsed[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    func(0);

    return 0;
}
