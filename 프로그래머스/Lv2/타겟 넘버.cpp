#include <bits/stdc++.h>
using namespace std;
int N;
int number[21];
int target;
int answer = 0;

void dfs(int L, int sum){
    if (L == N) {
        if (sum == target) answer++;
        return;
    }
    
    dfs(L+1, sum + number[L]);
    dfs(L+1, sum - number[L]);
}

int solution(vector<int> numbers, int t) {
    N = numbers.size();
    target = t;
    for (int i=0; i<N; i++) number[i] = numbers[i];
    
    dfs(0, 0);
    
    return answer;
}
