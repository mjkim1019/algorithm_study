#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
vector<int> arr[101];

void compress(int n){
    vector<int> v(arr[n].begin(), arr[n].end());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i=0; i<N; i++){
        int x = arr[n][i];
        int idx= lower_bound(v.begin(), v.end(), x) - v.begin();
        arr[n][i] = idx; // 순서로 대체
    }
}

bool compare(int x, int y){
    for (int i=0; i<N; i++){
        if (arr[x][i] != arr[y][i]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;

    cin >> M >> N;
   
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            int tmp; cin >> tmp;
            arr[i].push_back(tmp);
        }
        compress(i);
    }

    for (int i=0; i<M-1; i++){
        for (int j=i+1; j<M; j++){
            if (compare(i, j)) answer++;
        }
    }

    cout << answer;
    

    return 0;
}
