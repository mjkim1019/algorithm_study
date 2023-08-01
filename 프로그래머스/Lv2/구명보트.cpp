#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
 
    int last = people.size()-1;
    for (int i=0; i<people.size(); i++){
        int rest = limit - people[i];
        if (rest < people[i] || chk[i]) break;
        for (int j=last; j > i; j--){
            if (chk[j]) continue;
            if (rest >= people[j]){
                last = j;
                chk[j] = true; break;
            }
        }
    }
    
    for (int i=0; i<people.size(); i++) {
        if (!chk[i]) answer++; 
    }
    
    return answer;
}
