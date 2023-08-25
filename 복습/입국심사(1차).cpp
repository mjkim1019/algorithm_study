#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer;
    long long st = 1, en = 1e9*n;
    answer = en;
    
    while (st <= en){
        long long mid = (st+en)/2;
        long long cnt = 0;
        for (int t: times){
            cnt += mid/t;
        }
        if (cnt >= n){
            en = mid-1;
            answer = min(answer, mid);
        } else st = mid+1;
    }
    
    return answer;
}
