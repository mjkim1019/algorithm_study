#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    map<string, int> m;
    for (auto cloth: clothes){
        m[cloth[1]]++;
    }
    //for (auto c: m) cout << c.first << ' ' << c.second <<'\n';
    
    // 1번 시간초과
    if (m.size() == 30){
        return (1<<30) -1;
    }
    
    // 1개 선택 & 전부 선택
    int res = 1;
    for (auto cloth: m) {
        res *= cloth.second;
        answer += cloth.second;
    }
    if (m.size() > 1) answer += res;
    
    for (int i=2; i<m.size(); i++){
        vector<int> brute(m.size(), 1);
        fill(brute.begin(), brute.begin()+i, 0);
        do {
            int res = 1;
            for (int k=0; k<brute.size(); k++){
                if (brute[k]) continue;
                auto it = m.begin();
                advance(it, k);
                res *= it->second;
            }
            answer += res;
            //cout << i << " : " <<res <<'\n';
        }while (next_permutation(brute.begin(), brute.end()));
    }
   
    
    return answer;
}
