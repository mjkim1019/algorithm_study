#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b){
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, L;
    cin >> K >> L;

    vector<string> names;
    unordered_map<string, int> table; // 위치 저장
    for (int i = 0; i < L; i++)
    {
        string str;
        cin >> str;
        if (table.find(str) != table.end()) // 이미 존재
            table.erase(str);
        table[str] = i;
    }

    vector<pair<string, int>> slist(table.begin(), table.end());
    sort(table.begin(), table.end(), cmp);

    for (int i=0; i< min((int)slist.size(), K); i++){
        cout << slist[i].first <<'\n';
    }


    return 0;
}
