#include <bits/stdc++.h>

using namespace std;

int arr[27];

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    fill(arr, arr+27, 101);
    
    for (string key: keymap){
        for (int i=0; i<key.size(); i++){
            arr[key[i]-'A'] = min(i+1, arr[key[i]-'A']);
        }
    }
    
    for (string target: targets){
        int res = 0;
        int i;
        for (i=0; i<target.size(); i++){
            if (arr[target[i]-'A'] == 101) break;
            res += arr[target[i]-'A'];
        }
        if (i != target.size()) answer.push_back(-1);
        else answer.push_back(res);
    }
    
    return answer;
}
