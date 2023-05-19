#include <iostream>
#include <string>
#include <list>
using namespace std;

list<char> L;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    for (char c: str) L.push_back(c);
    list<char>::iterator t = L.end();

    int N;
    cin >> N;
    while (N--){
        char cmd;
        cin >> cmd;
        if (cmd == 'P'){
            char c; cin >> c;
            L.insert(t, c);
        } else if (cmd == 'L'){
            if (t != L.begin()) t--;
        } else if (cmd == 'D') {
            if (t != L.end()) t++;
        } else if (cmd == 'B') {
            if (t != L.begin()) t = L.erase(--t);
        }
    }
    for (char c: L) cout << c ;

    return 0;
}
