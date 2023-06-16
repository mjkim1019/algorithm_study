#include <string>
#include <vector>

using namespace std;

vector<string> p = {"aya", "ye", "woo", "ma"};
int used = -1;

bool isFound(string &s){
    int st = 0;
    while (st < s.size()){
        int n = -1;
        if (s[st] == 'a') n = 0;
        else if (s[st] == 'y') n =1;
        else if (s[st] == 'w') n =2;
        else if (s[st] == 'm') n = 3;

        if (n== -1 || used == n) return false;

        for (int i=0; i<p[n].size(); i++){
            if (s[st+i] != p[n][i]) return false;
        }
        used = n;
        st += p[n].size();
    }
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;

    for (string &s: babbling){
        used = -1;
        if (isFound(s)) answer++;
    }

    return answer;
}
