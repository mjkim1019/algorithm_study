#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
int ans;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N, cmp);
    
    for (int k=1; k<=N; k++){
        int val = arr[k-1] * k;
        ans = max(ans, val);
    }
    cout << ans;

    return 0;
}
