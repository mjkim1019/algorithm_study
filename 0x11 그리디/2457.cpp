#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &d1, pair<int, int> &d2){
    if (d1.first == d2.first){
        return d1.second > d2.second; // 끝나는 날짜 느린 거
    }
    return d1.first < d2.first; // 시작 날짜 빠른 거
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int> > flowers(N);
    for (int i=0; i<N; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a <3) {a = 3; b=1;}
        flowers[i] = make_pair(100*a+b, 100*c+d);
    }
    sort(flowers.begin(), flowers.end(), cmp);
    //for (auto i: flowers) cout << i.first << ' ' << i.second <<'\n';

    int ans = 0;
    int t = 301;
    while (t <1201){
        int nxt_t = t;
        for (int i=0; i<N; i++){
            if (flowers[i].first<= t && flowers[i].second > nxt_t){
                nxt_t = flowers[i].second; // 지는 날이 제일 긴 거 선택
            }
            if (flowers[i].first > t) break;
        }
        if (nxt_t == t) {cout << "0"; return 0;}
        ans++;
        t = nxt_t;
    }
    cout << ans;

    return 0;
}
