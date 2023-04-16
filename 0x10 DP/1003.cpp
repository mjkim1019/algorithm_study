#include <iostream>
using namespace std;

pair<int, int> d[42];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[0] = make_pair(1, 0);
    d[1] = make_pair(0, 1);
    d[2] = make_pair(1, 1);
    for (int i=3; i<=40; i++){
        int x = d[i-1].first + d[i-2].first;
        int y = d[i-1].second + d[i-2].second;
        d[i] = make_pair(x, y);
    }

    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        cout << d[N].first << ' ' << d[N].second <<'\n';
    }

    return 0;
}
