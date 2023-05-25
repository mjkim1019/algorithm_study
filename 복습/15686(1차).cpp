#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<pair<int, int> > houses, chickens;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++){
            int tmp;
            cin >> tmp;
            if (tmp == 1) houses.push_back(make_pair(i, j));
            else if (tmp == 2) chickens.push_back(make_pair(i, j));
        }

    int ans = 0x7f7f7f7f;
    vector<int> brute(chickens.size(), 1);
    fill(brute.begin(), brute.begin()+M, 0); // M개 선택
    do {
        int resDist = 0;
        for (auto house: houses){
            int mnDist = 2500;
            for (int i=0; i<brute.size(); i++){
                if (brute[i] == 1) continue;
                int dist = abs(house.X-chickens[i].X) + abs(house.Y-chickens[i].Y);
                mnDist = min(mnDist, dist);
            }
            resDist += mnDist;
        }
        ans = min(ans, resDist);
    }while (next_permutation(brute.begin(), brute.end()));

    cout << ans;

    return 0;
}
