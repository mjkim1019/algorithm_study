#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;

    int N, M;
    cin >> N >> M;
    vector<int> height(N);
    for (int i=0; i<N; i++) cin >> height[i];

    sort(height.begin(), height.end(), greater<>());
    int st = 0;
    int en = height[0];
    while (st <= en){
        int mid = (st + en)/2;
        int sum = 0;
        for (int & h: height){
            if (h > mid) sum += h-mid;
            else break;
        }
        if (sum >= M){
            answer = mid;
            st = mid+1;
        } else en = mid-1;
    }
    cout << answer;

    return 0;
}
