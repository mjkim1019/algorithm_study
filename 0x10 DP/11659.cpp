#include <iostream>
using namespace std;

int arr[100002];
int d[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, TC;
    cin >> N >> TC;
    for (int i=1; i<=N; i++) cin >> arr[i];

    d[1] = arr[1];
    for (int k=1; k<= N; k++){
        d[k] = d[k-1]+ arr[k];
    }

    while (TC--){
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i-1] <<'\n';
    }

    return 0;
}
