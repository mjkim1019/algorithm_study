#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a < b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while (TC--){
        int N, M;
        cin >> N >> M;

        vector<int> A;
        for (int i=0; i<N; i++) {
            int tmp; cin >> tmp;
            A.push_back(tmp);
        }
        vector<int> B;
        for (int i=0; i<M; i++) {
            int tmp;
            cin >> tmp;
            B.push_back(tmp);
        }

        sort(A.begin(), A.end(), cmp);
        sort(B.begin(), B.end());

        int cnt = 0;
        for (int a: A){
            for (int b: B){
                if (a > b) cnt++;
                else break;
            }
        }
        cout << cnt << '\n';
    }


    return 0;
}
