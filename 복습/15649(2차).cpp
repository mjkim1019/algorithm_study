#include <iostream>
using namespace std;

int N, M;
bool vis[10];
int arr[10];

void func(int L){
    if (L == M){
        for (int i=0; i<M; i++) cout << arr[i] <<' ';
        cout << '\n';
        return;
    }

    for (int i=1; i<=N; i++){
        if (vis[i]) continue;
        arr[L] = i;
        vis[i] = true;
        func(L+1);
        vis[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    func(0);

    return 0;
}
