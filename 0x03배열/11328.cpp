#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[30] = {0,};
    int n;
    string a, b;

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> a >> b;
        
        for (char c: a) arr[c-'a']++;
        for (char c: b) arr[c-'a']--;

        bool isPossible = true;
        for (int i: arr){
            if (i != 0) {
                isPossible = false;
                break;
            }
        }
        
        if (isPossible) cout << "Possible" << '\n';
        else cout << "Impossible" << '\n';

    }

    return 0;
}
