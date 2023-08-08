#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> & a, vector<int> &b){
    if (a[2] == b[2]) return true;
    return a[2] < b[2];
}

vector<int> p(105, -1);

int get_parent(int x){
    if (p[x] == -1) return x;
    return p[x] = get_parent(p[x]);
}

bool is_diff_group(int a, int b){
    a = get_parent(a);
    b = get_parent(b);
    
    if (a == b) return false;
    
    if (a < b) p[b] = a;
    else p[a] = b;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), cmp);
    int cnt = 0;
    for (auto &e: costs){
        if (!is_diff_group(e[0], e[1])) continue;
        answer += e[2];
        cnt++;
        if (cnt == n) break;
    }
    
    return answer;
}
