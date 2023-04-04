#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int ans[10];
int input[10];
bool isUsed[10];

void func(int L){
    if (L == M) {
        for (int i=0; i<M; i++) cout << input[ans[i]] << ' ';
        cout << '\n';
        return;
    }

    for (int i=0; i < N; i++){
        if (!isUsed[i]){
            ans[L] = i;
            isUsed[i] = true;
            func(L+1);
            isUsed[i] = false;
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
