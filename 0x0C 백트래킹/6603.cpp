#include <iostream>
#include <sstream>
using namespace std;

int K;
int input[15];
int ans[7];
bool isUsed[15];

void func(int L, int st){
    if (L== 6){
        for (int i=0; i<6; i++) cout << input[ans[i]] <<' ';
        cout << '\n';
        return;
    }

    for (int i=st; i<K; i++){
        if (!isUsed[i]){
            ans[L] = i;
            isUsed[i] = true;
            func(L+1, i+1);
            isUsed[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (true){
        cin >> K;
        if (!K) break;
      
        for (int i=0; i<K; i++){
            cin >> input[i];
        }

        func(0, 0);
        cout << '\n';
    }

    return 0;
}
