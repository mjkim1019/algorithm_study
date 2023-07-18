#include <iostream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    set<int> level[102]; // 난이도별로 문제 저장
    int number[100002]; // 문제 번호 : 난이도
    while (N--) {
        int a, b;
        cin >> a >> b;
        level[b].insert(a);
        number[a] = b;
    }

    int M;
    cin >> M;
    while (M--){
        string cmd;
        cin >> cmd;
        if (cmd == "add"){
            int a, b;
            cin >> a >> b;
            level[b].insert(a);
            number[a] = b;
        } else if (cmd == "recommend"){
            int n; cin >> n;
            if (n == 1){ // 가장 어려운 문제
                for(int i=100; i>=0; i--){
                    if (level[i].empty()) continue;
                    cout << *prev(level[i].end()) << '\n';
                    break;
                }
            } else if (n == -1){ // 가장 쉬운 문제
                for (int i=0; i<=100; i++){
                    if (level[i].empty()) continue;
                    cout << *(level[i].begin()) << '\n';
                    break;
                }
            }
        } else if (cmd == "solved"){
            int p; cin >> p;
            level[number[p]].erase(p);
            number[p] = 0;
        }
    }

    return 0;
}
