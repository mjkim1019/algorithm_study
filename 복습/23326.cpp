#include <iostream>
#include <vector>
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
    int cmd, x;
    while (Q--){
        cin >> cmd;
        if (cmd == 1){
            cin >> x;
            if (arr[x]) s.erase(x);
            else s.insert(x);
            
            arr[x] = !arr[x];
        } else if (cmd == 2){
            cin >> x;
            pos = (pos + x-1) % N + 1;
        } else if (cmd == 3){
            if (s.empty()){
                cout << -1 << '\n';
                continue;
            }

            auto it = s.lower_bound(pos);
            if (it == s.end()){
                cout << N + *s.begin() - pos << '\n';
            }
            else {
                cout << *it-pos << '\n';
            }
        }
    }

    return 0;
}
