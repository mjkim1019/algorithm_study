#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, ans=0;
    bool arr[000001] = {false, };

    cin >> n;
    for (int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr[temp] = true;
    }
    cin >> x;


    for (int i=1; i < x/2+1; i++){
        if (i >= x-i) break;
        if (arr[i] && arr[x-i]) ans++;
    }
    cout << ans;

    return 0;
}
