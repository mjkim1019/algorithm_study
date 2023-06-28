#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    vector<int> rope(N);
    for (int i=0; i<N; i++) cin >> rope[i];

    sort(rope.begin(), rope.end(), greater<>());

    ans = rope[0];
    for (int i=1; i<N; i++){
        ans = max(ans, rope[i]*(i+1));
    }

    cout << ans;

    return 0;
}
