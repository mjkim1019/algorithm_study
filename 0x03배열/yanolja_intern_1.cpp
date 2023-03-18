#include <iostream>
#include <vector>

using namespace std;

int arr[27];
int ans = 0;

int solution(string S) {
    for (char c: S) {
        arr[c-'A']++;
    }
    // BANANA -> B: 1 A: 3 N: 2
    while (arr['B'-'A'] >=1 && arr['A'-'A'] >=3 && arr['N'-'A'] >=2) {
        ans++;
        arr['B' - 'A'] -= 1;
        arr['A' - 'A'] -= 3;
        arr['N' - 'A'] -= 2;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

   cout << solution("BANANABANANANNNANABANNANANAA");

    return 0;
}
