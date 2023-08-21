#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int N = prices.size();
    for (int i=0; i<N-1; i++){
        int j;
        for (j=i+1; j<N; j++){
            if (prices[i] > prices[j]) {
                answer.push_back(j-i); break;
            }
        }
        if (j == N) answer.push_back(N-i-1);
    }
    answer.push_back(0);
    
    return answer;
}
