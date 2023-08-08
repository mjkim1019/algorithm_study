#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> answer;

    int A, B;
    cin >> A >> B;
    set<int> a;
    set<int> b;

    int tmp;
    for (int i=0; i<A; i++) {
        cin >> tmp;
        a.insert(tmp);
    }
    for (int i = 0; i < B; i++) {
        cin >> tmp;
        b.insert(tmp);
    }

    for (int x: a){
        if (b.find(x) == b.end()) answer.push_back(x);
    }

    cout << answer.size() << '\n';
    for (auto i: answer) cout << i <<' ';

    return 0;
}
