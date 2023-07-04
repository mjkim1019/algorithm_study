#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    vector<int> arr;
    int num;
    while (ss >> num) arr.push_back(num);
    
    answer += to_string(*min_element(arr.begin(), arr.end()));
    answer += " " + to_string(*max_element(arr.begin(), arr.end()));
    
    return answer;
}
