#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> Q;
    for (int i=0; i<priorities.size(); i++) 
        Q.push({priorities[i], i});
    
    sort(priorities.begin(), priorities.end(), greater<>());
    
    int pos = 0;
    while (!Q.empty() && pos<priorities.size()){
        auto cur = Q.front(); Q.pop();
        //cout << cur.X << ' ' << cur.Y << '\n';
        if (cur.X == priorities[pos]) {
            if (cur.Y == location) return pos+1;
            pos++;
        } else Q.push(cur);
    }
    
    
    return answer;
}
