#include <iostream>
#include <list>
#include <string>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    
    // 임의의 위치에서 삽입,삭제가 이루어지므로 링크드리스트 (O(1))
    list<char> L;
    for (char c: str) L.push_back(c);

    list<char>::iterator t = L.end();
    int m;
    cin >> m;
    while (m--){
        char cmd;
        cin >> cmd;
        
        if (cmd == 'P'){
            char c;
            cin >> c;
            L.insert(t, c);
        }
        else if (cmd == 'L'){
            if (t != L.begin()) t--;
        } else if (cmd == 'D'){
            if (t != L.end()) t++;
        } else if (cmd == 'B'){
            if (t != L.begin()) t = L.erase(--t);
        }
    }
    for (auto i: L) cout << i;

    return 0;
}
