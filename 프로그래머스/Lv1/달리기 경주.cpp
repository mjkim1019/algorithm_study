#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<int, string> m1; // 등수, 이름
    map<string, int> m2; // 이름, 등수
    
    for (int i=0; i<players.size(); i++){
        m2[players[i]] = i+1;
        m1[i+1] = players[i];
    }
    
    for (string name: callings){
        int rank = m2[name]--;
        string f = m1[rank-1];
        m2[f]++;
        m1[rank] = f;
        m1[rank-1] = name;
    }
    
    for (auto m: m1){
        answer.push_back(m.second);
    }
    
    return answer;
}
