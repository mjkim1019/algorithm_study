#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;

    int M, N;
    cin >> M >> N;
    vector<int> cookies(N);
    for (int i=0; i<N; i++) cin >> cookies[i];

    int st = 1;
    int en = *max_element(cookies.begin(), cookies.end());

    while (st <= en){
        int mid = (st+en)/2;
        int cnt = 0;
        for (int &k: cookies){
            cnt += k/mid;
        }
        
        if (cnt >= M) {
            answer = mid;
            st = mid+1;
        } else en = mid-1;
    }
    cout << answer;

    return 0;
}
