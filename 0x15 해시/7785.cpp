#include <iostream>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    unordered_set<string> S;

    while (N--)
    {
        string name, cmd;
        cin >> name >> cmd;
        if (cmd == "enter") S.insert(name);
        if (cmd == "leave") S.erase(name);
    }

    vector<string> answer(S.begin(), S.end());
    sort(answer.begin(), answer.end(), greater<>());

    for (auto &a : answer) cout << a << '\n';

    return 0;
}
