#include <bits/stdc++.h>
using namespace std;
#define N 5

char arr[N] = {'A','E','I','O','U'};
string word;
bool isFound = false;
int answer = 0;

void dfs(int L, string s){
    if (isFound) return;
    if (word == s) {
        isFound = true;
        return;
    }
    answer++;
    if (L == N) return;
    
    for (int i=0; i<N; i++){
        dfs(L+1, s+arr[i]);
    }
}

int solution(string w) {
    word = w;
    dfs(0, "");
    
    return answer;
}
