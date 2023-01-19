#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, v;
    int arr[210] = {0,};
    
    cin >> n;
    
    for (int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr[temp+100]++;
    }

    cin >> v;

    cout << arr[v+100];
    
    return 0;
}
