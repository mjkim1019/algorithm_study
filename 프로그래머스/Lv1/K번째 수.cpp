#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto &cmd: commands){
        vector<int> v;
        for (int i=cmd[0]-1; i<=cmd[1]-1; i++){
            v.push_back(array[i]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[cmd[2]-1]);
    }
    return answer;
}
