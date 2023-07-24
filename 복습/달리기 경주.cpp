#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> um; // 이름, 등수(0부터 시작)
    for (int i=0; i<players.size(); i++)
        um[players[i]] = i;
    
    for (string name: callings){
        int curRank = um[name];
        string ex_player = players[curRank-1];
        um[name]--; um[ex_player]++;
        swap(players[curRank], players[curRank-1]);
    }
    
    return players;
}
