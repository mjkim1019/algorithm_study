#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int i = 0;
    while (i<section.size()){
        answer++;
        int st = section[i];
        //cout << i <<'\n';
        if (i == section.size()-1) break;
        int j= i+1;
        for (j=i+1; j<section.size(); j++){
            if (section[j] >= st+m) break;
        }
        i = j;
        //cout << "next : " << i <<'\n';
    }
    
    return answer;
}
