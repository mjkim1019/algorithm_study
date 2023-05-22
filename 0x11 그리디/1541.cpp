#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;

    bool isMinus = false;
    int ans = 0;
    int st = 0;
    for (int idx=0; idx<str.size(); idx++){
        //cout << "idx = " << idx <<'\n';
        if (str[idx] == '-'){
            isMinus = true; continue;
        } else if (str[idx] == '+') continue;

        int i = idx;
        while (str[i] >= '0' && str[i] <='9') i++; 
        
        int num = stoi(str.substr(idx, i-idx));
        if (isMinus) ans -= num;
        else ans += num;
        
        if (i == str.size()) break;
        idx = i-1;
    }
    
    
    cout << ans;

    return 0;
}
