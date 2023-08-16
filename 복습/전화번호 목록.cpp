#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i=0; i<phone_book.size()-1; i++){
        bool isFound = true;
        for (int j=0; j<phone_book[i].size(); j++){
            if (phone_book[i][j] != phone_book[i+1][j]) {
                isFound = false; break;
            }
        }
        if (isFound) return false;
    }
    
    return true;
}
