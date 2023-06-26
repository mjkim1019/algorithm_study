#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int N, M;
int ans = 0x7f7f7f7f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    vector<pair<int, int> > chickens;
    vector<pair<int, int> > houses; 
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++){
            int tmp;
            cin >> tmp;
            if (tmp == 2){
                chickens.push_back(make_pair(i, j));
            } else if (tmp == 1){
                houses.push_back(make_pair(i, j));
            }
        }

    vector<int> brute(chickens.size(), 1);
    fill(brute.begin(), brute.begin()+M, 0);
    
    do{
        int res = 0;
        for (auto house: houses){
            int dist = 0x7f7f7f7f;
            for (int j=0; j<chickens.size(); j++){
                if (brute[j] != 0) continue;
                auto chicken = chickens[j];
                dist = min(dist, abs(house.X - chicken.X) + abs(house.Y - chicken.Y));
            }
            res += dist;
        }
        ans = min(ans, res);
    }while(next_permutation(brute.begin(), brute.end()));

    cout << ans;

    return 0;
}
