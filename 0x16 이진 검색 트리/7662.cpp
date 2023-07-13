#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
    multiset<int> S;
    int K; cin >> K;
    while (K--){
        char cmd;
        int n;
        cin >> cmd >> n;
        if (cmd == 'I') S.insert(n);
        else if (cmd == 'D'){
            if (S.empty()) continue;
            if (n == 1) {
                auto it = prev(S.end());
                S.erase(it);
            }else {
                S.erase(S.begin());
            } 
        }
    }
    if (S.empty()) cout << "EMPTY" << '\n';
    else
        cout << *prev(S.end()) << ' ' << *S.begin() << '\n';
    }

    return 0;
}
