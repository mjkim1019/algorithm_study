#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> apeach;
vector<int> ryan;
int mx = -101;
vector<int> answer;

bool cmp(vector<int> ryan) {
    for(int i = 10; i >= 0; i--) {
        if(ryan[i] > answer[i]) return true;
        else if (ryan[i] < answer[i]) return false;
    }
}

int cal(){
    int a_sum=0, r_sum=0;
    for (int i=0; i<11; i++){
        if (apeach[i] == 0 && ryan[i] == 0) continue;
        int score = 10-i;
        if (apeach[i] >= ryan[i]) a_sum += score;
        else r_sum += score;
    }

    return r_sum - a_sum;
}

void check(){
    int score_diff = cal();
    if (score_diff >= mx) {
        if (score_diff == mx && !cmp(ryan)) return;
        answer = ryan;
        mx = score_diff;
        //cout << mx <<'\n';
    }
}

void dfs(int cnt, int idx){
    if (cnt == N){
        check();
        return; 
    } 
    else if (idx == 10) {
        ryan[idx] = N-cnt;
        dfs(N, idx+1);
        ryan[idx] = 0;
        return;
    }

    if (N-cnt >= apeach[idx]+1){
        ryan[idx] = apeach[idx]+1;
        dfs(cnt+ryan[idx], idx+1);   
        ryan[idx] = 0;
    }

    dfs(cnt, idx+1);
    ryan[idx] = 0;
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    apeach = info;
    ryan = vector<int>(info.size(), 0);
    dfs(0, 0);
    if (mx <= 0) answer = {-1};

    return answer;
}
