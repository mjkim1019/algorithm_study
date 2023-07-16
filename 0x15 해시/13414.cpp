#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, L;
    cin >> K >> L;

    vector<string> names;
    unordered_map<string, int> table; // 위치 저장
    for (int i=0; i<L; i++){
        string str;
        cin >> str;
        if (table.find(str) != table.end())
            names[table[str]-1] = "";
        table[str] = i+1;
        names.push_back(str);
    }

    //cout <<'\n';
    int cnt = 0;
    for (string name: names){
        if (name == "") continue;
        cout << name <<'\n';
        cnt++;
        if(cnt == K) break;
    }

    return 0;
}
