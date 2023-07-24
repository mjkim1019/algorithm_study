#include <bits/stdc++.h>

using namespace std;

int N;
bool vis[10];
string number;
unordered_set<int> us;

bool is_prime(string str){
    int num = stoi(str);
    if (num <= 1) return false;
    for (int i=2; i*i<=num; i++){
        if (num % i == 0) return false;
    }
    //cout << str <<'\n';
    return true;
}

void dfs(int L, string str){
    if (str != "" && is_prime(str)) us.insert(stoi(str));
    if (L == N) return;
    
    for (int i=0; i<N; i++){
        if (vis[i]) continue;
        vis[i] = true;
        dfs(L+1, str+number[i]);
        vis[i] = false;
    }
}

int solution(string numbers) {
    N = numbers.size();
    number = numbers;
    dfs(0, "");
    
    return us.size();
}
