#include <iostream>
#include <stdlib.h>
#include <vector>
#define X first
#define Y second
using namespace std;

int N, M;
vector<pair<int, int> > home;
vector<pair<int, int> > chicken;
int ans = 50000;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1){
                home.push_back(make_pair(i, j));
            } else if (tmp == 2){
                chicken.push_back(make_pair(i, j));
            }
        }

    
    vector<int> v;
    for (int i = 0; i < M; i++)
        v.push_back(0);
    for (int i = 0; i < chicken.size() - M; i++)
        v.push_back(1);

    // chicken.size() 중에 M개 뽑기
    do
    {
        vector<int> idx;
        for (int i = 0; i < chicken.size(); i++)
        {
            if (v[i] == 0){
                idx.push_back(i);
                //cout << i << ' ';
            }
        }   
        //cout << '\n';
        // 치킨 거리 구하는작업
        int distance = 0;
        for (auto h: home){
            int dist = 101;
            for (int i: idx){
                dist = min(dist, abs(h.X - chicken[i].X) + abs(h.Y - chicken[i].Y));
            }
            distance += dist;
        }
        ans = min(distance, ans);

    } while (next_permutation(v.begin(), v.end()));

    cout << ans;

    return 0;
}
