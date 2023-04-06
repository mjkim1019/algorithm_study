#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int input[10];
int ans[10];

void func(int L) {
    if (L == M){
        for (int i=0; i<M; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    int tmp = 0;
    for (int i=0; i<N; i++){
        if (tmp != input[i]){
        ans[L] = input[i];
        tmp = input[i];
        func(L+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> input[i];
    sort(input, input+N);
    func(0);

    return 0;
}
