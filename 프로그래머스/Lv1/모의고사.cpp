#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer = {};
    vector<int> a = {1, 2, 3, 4, 5}; //5
    vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5}; //8
    vector<int> c = {3,3, 1,1, 2,2, 4,4, 5,5}; //10
    
    vector<int> v(3, 0);
    for (int i=0; i<answers.size(); i++){
        if (a[i%5] == answers[i]) v[0]++;
        if (b[i%8] == answers[i]) v[1]++;
        if (c[i%10] == answers[i]) v[2]++;
    }
    
    int mx_idx = max_element(v.begin(), v.end()) - v.begin();
    answer.push_back(mx_idx+1);
    
    for (int i=0; i<3; i++){
        if (i==mx_idx) continue;
        if (v[mx_idx] == v[i]) answer.push_back(i+1);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
