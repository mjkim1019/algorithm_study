#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N+1);
    set<int> s;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        if (arr[i]) s.insert(i);
    }
    int pos = 1;
    while (Q--){
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int num; cin >> num;
            if (arr[num]) s.erase(num);
            else s.insert(num);

            arr[num] = !arr[num];
        }
        else if (cmd == 2){
            int x; cin >> x;
            pos = (pos+x-1) % N + 1;
        } else if (cmd == 3){
            if (s.empty()) {
                cout << -1 <<'\n'; 
                continue;
            }

            int dist = 0;
            auto it = s.lower_bound(pos);
            if (it != s.end()) dist = *it - pos; 
            else { // 한바퀴 돌아야 함
                dist = *s.begin() + N-pos;
            }
            cout << dist << '\n';
        }
    }
   

    return 0;
}
