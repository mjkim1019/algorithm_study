#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_multiset<string> p;
    for (string name: participant) p.insert(name);
    for (string name: completion){
        p.erase(p.find(name));
    }
    return *p.begin();
}
