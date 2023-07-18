#include <iostream>
#include <set>
#include <unordered_map>
#define X first
#define Y second

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    set<pair<int, int> > s; // 난이도, 번호
    unordered_map<int, int> m; // 문제 번호 : 난이도
    while (N--) {
        int a, b;
        cin >> a >> b;
        s.insert({b, a});
        m[a] = b;
    }

    int M;
    cin >> M;
    while (M--){
        string cmd;
        cin >> cmd;
        if (cmd == "add"){
            int a, b;
            cin >> a >> b;
            s.insert({b, a});
        } else if (cmd == "recommend"){
            int n; cin >> n;
            if (n == 1){
                auto num = *prev(s.end());
                cout << num.Y << '\n';
            } else if (n == -1){
                cout << (*s.begin()).Y <<'\n';
            }
        } else if (cmd == "solved"){
            int p; cin >> p;
            if (m.find(p) != m.end()) {
                int level = m.find(p) -> second;
                s.erase({level, p});
            }
        }
    }

    return 0;
}
