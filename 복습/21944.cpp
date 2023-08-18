#include <bits/stdc++.h>
using namespace std;

pair<int, int> number[100005]; // 문제번호 : {알고리즘, 난이도}
set<pair<int, int>> algo[105]; // 알고리즘 : {난이도, 문제번호}
set<int> level[105]; // 난이도 : {문제번호}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
   
    while (N--){
        int p, l, g;
        cin >> p >> l >> g;
        number[p] = {g, l};
        algo[g].insert({l, p});
        level[l].insert(p);
    }

    int M; cin >> M;
    string cmd;
    int a, b, c;
    while (M--){
        cin >> cmd;
        if (cmd == "recommend") {
            cin >> a >> b;
            if (b == 1) {
                auto it = algo[a].end();
                cout << (*--it).second <<'\n';
            } else if (b == -1) {
                auto it = algo[a].begin();
                cout << (*it).second <<'\n';
            }
        } else if (cmd == "recommend2"){
            cin >> a;
            if (a == 1) {
                for (int i=100; i >=0; i--){
                    if (level[i].empty()) continue;
                    cout << *(--level[i].end()) <<'\n';
                    break;
                }
            } else if (a == -1) {
                for (int i=1; i<=100; i++){
                    if (level[i].empty()) continue;
                    cout << *(level[i].begin()) << '\n';
                    break;
                }
            }

        } else if (cmd == "recommend3") {
            cin >> a >> b;
            int res = -1;
            if (a == 1){
                for (int i=b; i<=100; i++){
                    if (level[i].empty()) continue;
                    res = *(level[i].begin());
                    break;
                }
            } else if (a == -1) {
                for (int i=b-1; i>=1; i--){
                    if (level[i].empty()) continue;
                    res = *(--level[i].end());
                    break;
                }
            }
            cout << res << '\n';
        } else if (cmd == "add"){
            cin >> a >> b >> c;
            number[a] = {c, b};
            algo[c].insert({b, a});
            level[b].insert(a);
        } else if (cmd == "solved"){
            cin >> a;
            int g, l;
            tie(g, l) = number[a];
            algo[g].erase({l, a});
            level[l].erase(a);
        }
    }


    return 0;
}
