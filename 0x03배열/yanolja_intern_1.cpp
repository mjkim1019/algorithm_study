#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[27];
int ans = 0;

int solution(string S) {
    for (char c: S) {
        arr[c-'A']++;
    }
    // BANANA -> B: 1 A: 3 N: 2
    int b = arr['B'-'A'];
    int a = arr['A'-'A']/3;
    int n = arr['N'-'A']/2;
    ans = min(min(b,n), a);

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

   cout << solution("BANANABANANANNNANABANNANANAA");

    return 0;
}
