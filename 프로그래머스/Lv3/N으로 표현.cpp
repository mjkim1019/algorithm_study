#include <bits/stdc++.h>
using namespace std;

set<int> d[10];

int solution(int N, int number) {
    int tmp = 0;
    for (int k=1; k<=8; k++) {
        tmp = 10*tmp +N;
        d[k].insert(tmp);
    }
    
    for (int k=1; k<=8; k++){
        for (int i=1; i<k; i++){
            for (int a: d[i]){
                for (int b: d[k-i]){
                    d[k].insert(a+b);
                    d[k].insert(a-b);
                    d[k].insert(a*b);
                    if (b != 0) d[k].insert(a/b);
                }
            }
        }
    }
    
    for (int k=1; k<=8; k++){
        if (d[k].find(number) != d[k].end()) return k;
    }
    
    return -1;
}
