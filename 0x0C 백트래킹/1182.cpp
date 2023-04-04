#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int input[21];
int isUsed[21];
int ans = 0;

void func(int L) {
    if (L == N){
        int sum = 0;
        bool isEmpty = true;
        for (int i=0; i<N; i++){
            if (isUsed[i]){
                sum += input[i];
                isEmpty = false;
            }
        }

        if (!isEmpty && sum == S) ans++;
        return;
    }
    
    isUsed[L] = true;
    func(L+1);
    isUsed[L] = false;
    func(L+1);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for (int i=0; i<N; i++) cin >> input[i];
    func(0);
    cout << ans;

    return 0;
}
