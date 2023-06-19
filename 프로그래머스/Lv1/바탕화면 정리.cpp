#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int a = wallpaper.size();
    int b = wallpaper[0].size();
    int c = 0;
    int d = 0;
    
    for (int i=0; i<wallpaper.size(); i++){
        for (int j=0; j<wallpaper[i].size(); j++){
            if (wallpaper[i][j] == '#') {
                a = min(a, i);
                b = min(b, j);
                c = max(c, i);
                d = max(d, j);
            }
        }
    }
    
    
    return {a, b, c+1, d+1};
}
