#include <iostream>
using namespace std;

int alphabet[26];

int solution(string str){
    int ans = 0;

    for (char c: str){
        alphabet[c-'a']++;
    }
    
    for (int i=0; i<='z'-'a'; i++){
        if (alphabet[i] % 2 == 1) ans++;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str = "abebeaedeac";
    cout << solution(str);

    return 0;
}
