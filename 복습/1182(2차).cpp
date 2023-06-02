#include <iostream>
#include <vector>
using namespace std;

int N, S;
int ans = 0;
vector<int> input;

void dfs(int sum, int idx){
    if (idx == N){
        if (sum == S) ans++;
        return;
    }

    dfs(sum+input[idx], idx+1);
    dfs(sum, idx+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> S;
    input = vector<int>(N);
    for (int i=0; i<N; i++) cin >> input[i];

    dfs(0, 0);    
    if (S == 0) ans--;
    cout << ans;

    return 0;
}
