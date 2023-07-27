#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0;
    for (auto &c: name) answer += min(c-'A', 'Z'-c+1);
    
    int min_move = name.size()-1;
    for (int i=0; i<name.size(); i++){
        int nxt = i+1;
        while (nxt<name.size() && name[nxt] =='A') nxt++; // 연속된 A 세기
        min_move = min(min_move, 2*i + (int)name.size()-nxt); // 순으로 갔다가 역으로 변경
        min_move = min(min_move, 2*((int)name.size()-nxt) + i); // 역으로 왔다가 순으로 변경       
    }
    
    
    return answer+min_move;
}
