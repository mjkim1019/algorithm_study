#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[27] = {0,};
    int b[27] = {0,};

    string x, y;
    cin >> x >> y;

    for (char c: x) a[c-'a']++;
    for (char c: y) b[c-'a']++;

    int ans = 0;
    for (int i=0; i<27; i++){
        if (a[i] > b[i]) {
           while (a[i] > b[i]) {
            a[i]--;
            ans++;
           }
        } else if (a[i] < b[i]) {
            while (a[i] < b[i]) {
                b[i]--;
                ans++;
            }
        } 
    }
    cout << ans;

    return 0;
}
