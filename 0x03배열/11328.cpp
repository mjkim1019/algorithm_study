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
        if (a.size() != b.size()){
            cout << "Impossible" << '\n';
            continue;
        }

        memset(arr, 0, sizeof(arr));
        for (char c: a){
            arr[c-'a']++;
        }
        bool isNext = false;
        for (char c: b){
            if (arr[c-'a'] <= 0) {
                cout << "Impossible" << '\n';
                isNext = true;
                break; 
            }
            arr[c-'a']--;
        }
        if (isNext) continue;

        cout << "Possible" << '\n';
    }

    return 0;
}
