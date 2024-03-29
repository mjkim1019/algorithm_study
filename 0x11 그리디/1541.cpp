#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;

    int sign = 1;
    int ans = 0;
    int tmp = 0;
    for (int i=0; i<str.size(); i++){
        if (str[i] == '-' || str[i] == '+') {
            ans += tmp *sign;
            if (str[i] == '-') sign = -1;
            tmp = 0;
        }
        else {
            tmp *= 10;
            tmp += str[i] - '0';
        }
    }

    ans += tmp*sign;
    cout << ans;

    return 0;
}
