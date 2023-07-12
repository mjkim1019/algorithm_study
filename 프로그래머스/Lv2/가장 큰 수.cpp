#include <bits/stdc++.h>

using namespace std;

bool cmp(int x, int y){
    string a = to_string(x) + to_string(y);
    string b = to_string(y) + to_string(x);
    
    return a > b;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    for (int i=0; i<numbers.size(); i++){
        if (numbers[0] == 0) { answer = "0"; break;}
        answer += to_string(numbers[i]);
    }
    
    return answer;
}
