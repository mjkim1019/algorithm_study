#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    vector<int> d(K+1, 0);
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    d[0] = 1;
    for (int i=0; i<arr.size(); i++){
        for (int k=arr[i]; k <= K; k++){
            d[k] += d[k-arr[i]];
        }
    }
    
    cout << d[K];
    //for (int i=0; i<=K; i++) cout << d[i] <<' ';
    

    return 0;
}
