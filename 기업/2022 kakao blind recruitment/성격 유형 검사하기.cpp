#include <bits/stdc++.h>
using namespace std;

int score[] = {0, 3, 2, 1, 0, 1, 2, 3};
int result[4][2];
unordered_map<char, int> M;
char name[] = {'R', 'T', 'C','F','J','M','A','N'};


string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for (int i=0; i<8; i++) M[name[i]] = i;
    
    for (int n=0; n<survey.size(); n++){
        int pos;
        if (choices[n] <= 3) pos = 0;
        else pos = 1;
        int i = M[survey[n][pos]] /2;
        int j = M[survey[n][pos]] %2;
        result[i][j] += score[choices[n]];
    }
    
    for (int i=0; i<4; i++){
        if (result[i][0] >= result[i][1]) answer += name[i*2+0];
        else answer += name[i*2+1];
    }
    
    return answer;
}
