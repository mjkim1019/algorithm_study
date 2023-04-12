#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while (TC--){
        int N, M;
        cin >> N >> M;

        vector<pair<int, int> > v;
        
        for (int i=0; i<N; i++) {
            int tmp; cin >> tmp;
            v.push_back(make_pair(tmp, 0)); // A
        }
        for (int i=0; i<M; i++) {
            int tmp;
            cin >> tmp;
            v.push_back(make_pair(tmp, 1)); // B
        }

        sort(v.begin(), v.end());

        int cnt=0;
        int ans = 0;
        for (int i=0; i< N+M; i++){
            if (v[i].second == 0) {
                ans += cnt;
            } else cnt++; // b가 더 작음 
        }

        
        cout << ans << '\n';
    }


    return 0;
}
