#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if (s[0] != ' ' && !isdigit(s[0])) s[0] = toupper(s[0]);
    for (int i=1; i<s.size(); i++){
        if (s[i] == ' ') continue;
        if (isdigit(s[i])) continue;
        if (s[i-1] == ' ') s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
    }
    answer = s;
    
    return answer;
}
