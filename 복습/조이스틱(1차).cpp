#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    
    for (int i=0; i<name.size(); i++){
        answer += min('Z'- name[i]+1, name[i]-'A');
    }
    if (answer == 0) return 0;
    
    int move = len-1;
    for (int i=0; i<len; i++) {
        int next_i = i+1;
        while (next_i < len && name[next_i] == 'A') 
            next_i++;
        
        move = min(move, (len-next_i+i + min(i, len-next_i)));
    }
    
    return answer+move;
}
