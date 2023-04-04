#include <iostream>
using namespace std;

int N, M;
int arr[10];
bool isUsed[10];

void func(int n){
    if (n == M){
        for (int i=0; i<M; i++) cout << arr[i] <<' ';
        cout << '\n';
        return;
    }

    for (int i=1; i<=N; i++){
        if (!isUsed[i]){
            arr[n] = i;
            isUsed[i] = true;
            func(n+1);
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
