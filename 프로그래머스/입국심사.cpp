#include <bits/stdc++.h>
#define ll long long

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    // n명을 심사하는데 걸리는 시간
    ll st = *min_element(times.begin(), times.end()); // 최소 시간
    ll en = *max_element(times.begin(), times.end()) * n / times.size(); // 최대 시간
    
    while(st <= en){
        ll mid = (st+en)/2;
        ll cnt = 0;
        for (int i=0; i<times.size(); i++){
            cnt += mid / times[i];
        }

        if (cnt >= n) {
            en = mid -1;
            answer = mid;
        } else {
            st = mid +1;
        }
    }
    
    return answer;
}
