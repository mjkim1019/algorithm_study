#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<int> arr(N+1);
    int data = 0;
    for (int i=1; i<=N; i++) cin >> arr[i];
    
    d[1] = arr[1];
    for (int i=2; i<=N; i++)
        d[i] = d[i-1] + arr[i];

    while (M--){
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a-1] <<'\n';
    }

    return 0;
}
