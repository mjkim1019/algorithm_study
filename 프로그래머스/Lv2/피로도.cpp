#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    vector<int> brute;
    for (int i=0; i<dungeons.size(); i++) brute.push_back(i);
    
    do{
        int res = 0;
        int ph = k;
        for (int &i: brute){
            if (ph < dungeons[i][0]) break; // 필요
            ph -= dungeons[i][1]; // 소모
            res++;
        }
        answer = max(res, answer);
    }while (next_permutation(brute.begin(), brute.end()));
    
    
    return answer;
}
