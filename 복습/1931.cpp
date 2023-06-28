#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int> > v(N); // 끝나는 시각, 시작 시각
    for (int i=0; i<N; i++)
        cin >> v[i].Y >> v[i].X;
    
    sort(v.begin(), v.end());

    int st = -1;
    for (int i=0; i<N; i++){
        if (st > v[i].Y) continue;
        ans++;
        st = v[i].X;
    }

    cout << ans;

    return 0;
}
