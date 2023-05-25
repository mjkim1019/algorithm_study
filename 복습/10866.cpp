#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> DQ;
    int N;
    cin >> N;
    while (N--){
        string cmd;
        cin >> cmd;
        if (cmd == "push_front"){
            int n; cin >> n;
            DQ.push_front(n);
        } else if (cmd == "push_back"){
            int n; cin >> n;
            DQ.push_back(n);
        } else if (cmd == "pop_front"){
            if (DQ.empty()) cout << "-1\n";
            else {
                cout << DQ.front() <<'\n';
                DQ.pop_front();
            }
        } else if (cmd == "pop_back"){
            if (DQ.empty()) cout << "-1\n";
            else {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        } else if (cmd == "size"){
            cout << DQ.size() <<'\n';
        } else if (cmd == "empty"){
            cout << DQ.empty() << '\n';
        } else if (cmd == "front"){
            if (DQ.empty()) cout << "-1\n";
            else cout << DQ.front() <<'\n';
        } else if (cmd == "back"){
            if (DQ.empty()) cout << "-1\n";
            else cout << DQ.back() <<'\n';
        }
    }

   
    return 0;
}
