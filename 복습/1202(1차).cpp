#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define X first
#define Y second
#define ll long long

bool cmp(pair<int, int> &a, pair<int, int> &b){
    if (a.X != b.X) return a.X > b.X;
    return a.Y < b.Y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll answer = 0;

    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> dia(N); // {가격, 무게}
    for (int i=0; i<N; i++) cin >> dia[i].Y >> dia[i].X;
    sort(dia.begin(), dia.end(), cmp);   
    
    multiset<int> bag; // erase가 빈번하기 때문에 이진검색트리로
    for (int i=0; i<K; i++) {
        int tmp; cin >> tmp;
        bag.insert(tmp);
    }

    int cnt = 0;
    for (int i=0; i<N; i++){
        if (bag.empty()) break;
        auto it = bag.lower_bound(dia[i].Y);    
        if (it == bag.end()) continue;
        cnt++;
        answer += dia[i].X;
        if (cnt == K) break;
        bag.erase(it);
    }
    cout << answer;

    return 0;
}
