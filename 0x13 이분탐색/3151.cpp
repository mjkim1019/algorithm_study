#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long answer =0;

    int N;
    cin >> N;
    vector<int> member(N);
    

    for (int i=0; i<N; i++) cin >> member[i];
    sort(member.begin(), member.end());

    for (int i=0; i<N-1; i++){
        for (int j=i+1; j<N; j++){
            auto ub = upper_bound(member.begin()+j+1, member.end(), -member[i] - member[j]);
            auto lb = lower_bound(member.begin()+j+1, member.end(), -member[i]-member[j]);
            answer += ub - lb;
        }
    }

    cout << answer;

    return 0;
}
