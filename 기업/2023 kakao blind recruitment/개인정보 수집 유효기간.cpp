#include <bits/stdc++.h>

using namespace std;

map<char, int> M;

int stringToDaysum(string str){
    int year = stoi(str.substr(0, 4));
    int mm = stoi(str.substr(5,2));
    int dd = stoi(str.substr(8,2));
    
    return year*12*28 + mm*28 + dd;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int todaySum = stringToDaysum(today);
    
    for (string term: terms){
        stringstream ss(term);
        char c;
        int n;
        ss >> c;
        ss >> n;
        M[c] = n;
    }

    
    for (int i=0; i<privacies.size(); i++){
        stringstream ss(privacies[i]);
        string str;
        ss >> str;
        int sumday = stringToDaysum(str);
        char c;
        ss >> c;
        int limit = M[c]*28 + sumday;
        
        if (todaySum >= limit) answer.push_back(i+1);
    }
    
    return answer;
}
