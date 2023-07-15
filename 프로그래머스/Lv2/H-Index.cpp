#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    for (int i=0; i<10001; i++){
        int cnt = citations.end() - lower_bound(citations.begin(), citations.end(), i);
        if (cnt == 0) break;
        if (cnt >= i) answer = i;
    }
    
    return answer;
}
