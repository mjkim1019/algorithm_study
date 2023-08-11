#include <iostream>
#include <vector>
using namespace std;
#define X first
#define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = -1;

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> v;
    for (int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());
    int st = v[0].X;
    int en = v[0].Y;
    while (st <= en){
        int mid = (st+en)/2;
        int cnt = 0;
        for (auto &t: v){
            if (t.Y < mid) continue;
            if (t.X > mid) break;
            cnt++;
        }
        if (cnt >= M){
            answer = mid;
            en = mid -1;
        } else st = mid +1;
    }

    cout << answer;

    return 0;
}
