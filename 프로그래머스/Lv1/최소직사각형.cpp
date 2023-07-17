#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    for (auto &size: sizes){
        sort(size.begin(), size.end());
    }
    
    int mx_w = 0, mx_h = 0;
    for (auto size: sizes){
        mx_w = max(mx_w, size[0]);
        mx_h = max(mx_h, size[1]);
    }
    return mx_w*mx_h;
}
