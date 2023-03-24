#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;
    stack<char> S;
    bool isValid = false;
    int cnt = 0;
    for (char c: str){
        if (c == '('){
            S.push(c);
            isValid = true;
        } 
        else if (c == ')') {
            if (isValid){
                S.pop();
                cnt += S.size();
                isValid = false;
            } else {
                S.pop();
                cnt +=1;
            }
        }
    }
    cout << cnt;

    return 0;
}
