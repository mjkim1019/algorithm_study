#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[2][27] = {0,};

    string x, y;
    cin >> x >> y;

    for (char c: x) arr[0][c-'a']++;
    for (char c: y) arr[1][c-'a']++;

    int ans = 0;
    for (int i=0; i<27; i++){
        ans += abs(arr[0][i]-arr[1][i]);
    }
    cout << ans;

    return 0;
}
