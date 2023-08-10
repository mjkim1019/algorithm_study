#include <bits/stdc++.h>
using namespace std;

// 구하는 것 : begin -> target 몇 단계에 거쳐 변하는지
// 3 <= 단어의 길이 <= 10, 모든 단어의 길이 같음!
// 3 <= words.size() <= 50
// 0~length-1 까지 중 하나 선택해서 있는 지 확인 -> dfs

vector<string> words;
string target;
int answer;
bool isUsed[51];

void dfs(int cnt, string str){
    if (cnt > answer) return;
    if (str == target) {
        answer = min(answer, cnt);
        return;
    }
    vector<int> brute(str.size(), 1);
    brute[0] = 0;
    
    do{
        for (int idx=0; idx<words.size(); idx++){
            if (isUsed[idx]) continue;
            string w = words[idx];
            bool find = true;
            for (int i=0; i<w.size(); i++){
                if (brute[i] == 0) continue;
                if (w[i] != str[i]) {
                    find = false;
                    break;
                }
            }
            //cout << str << ' ' << w << " find = "<< find <<'\n';
            if (find) {
                isUsed[idx] = true;
                dfs(cnt+1, w);
                isUsed[idx] = false;
            }
        }
        
    }while (next_permutation(brute.begin(), brute.end()));
}

int solution(string begin, string t, vector<string> w) {
    words = w;
    target = t;
    answer = w.size();
    dfs(0, begin);
    if (answer == w.size()) return 0;
    
    return answer;
}
