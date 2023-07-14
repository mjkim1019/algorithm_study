#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    
    unordered_set<string> s;
    for (string& number: phone_book) s.insert(number);
    
    for (int i=0; i<phone_book.size(); i++){
        string number = "";
        for (int j=0; j<phone_book[i].size(); j++){
            number += phone_book[i][j];
            if (s.find(number) != s.end() && number != phone_book[i]) return false;
        }
    }
    
    return true;
}
