#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> score;
char name[4][2] = {
    {'R', 'T'},
    {'C', 'F'},
    {'J', 'M'},
    {'A', 'N'},
};

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";

    for (int i = 0; i < survey.size(); i++)
    {
        if (choices[i] <= 3)
            score[survey[i][0]] += 4-choices[i];
        else
            score[survey[i][1]] += choices[i]-4;
    }

    for (int i = 0; i < 4; i++)
    {
        if (score[name[i][0]] >= score[name[i][1]]) answer += name[i][0];
        else answer += name[i][1];
    }

    return answer;
}
