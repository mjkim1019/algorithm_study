#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while (s != "1"){
        answer[0]++;
        
        int n = 0;
        for (char c: s) if (c == '1') n++;
        answer[1] += s.size() - n;
        
        string res;
        while (n > 1){
            res += to_string(n%2);
            n /= 2;
        }
        if (n == 1) res += "1";
        reverse(res.begin(), res.end());
        s = res;
    }
    
    return answer;
}
