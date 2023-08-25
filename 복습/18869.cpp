#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> universe[101];

void compact(vector<int> &arr){
    vector<int> v(arr.begin(), arr.end());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i=0; i<arr.size(); i++){
        int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        arr[i] = idx;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;

    int M, N;
    cin >> M >> N;
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            int tmp; cin >> tmp;
            universe[i].push_back(tmp);
        }
        compact(universe[i]);
    }

    for (int i=0; i<M; i++){
        auto v1 = universe[i];
        for (int j=i+1; j<M; j++){
            auto v2 = universe[j];
            bool is_able = true;
            for (int k=0; k<N; k++){
                if (v1[k] != v2[k]) {
                    is_able = false;
                    break;
                }
            }
            if (is_able) answer++;
        }
    }
    cout << answer;


    return 0;
}
