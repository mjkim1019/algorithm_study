#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int l=0, r=people.size()-1;
    while (l<r){
        if (people[l]+people[r] <= limit) {
            l++; r--;
            answer++;
        }
        else r--;
    }
    
    return people.size() - answer;
}
