#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    for (string &op: operations){
        stringstream ss(op);
        char cmd;
        int num;
        ss >> cmd >> num;
        if (cmd == 'I') ms.insert(num);
        else if (cmd == 'D'){
            if (ms.empty()) continue;
            if (num == 1)
                ms.erase(--ms.end());
            else if (num == -1)
                ms.erase(ms.begin());        
        }
    }
    
    if (ms.empty()) return {0,0};
    else return {*(--ms.end()), *ms.begin()};
    
}
