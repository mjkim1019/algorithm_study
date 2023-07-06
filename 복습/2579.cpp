#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[305][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N+1);
    for (int i=1; i<=N; i++) cin >> arr[i];

    d[0][1] = 0; d[0][2] = 0;
    d[1][1] = arr[1];
    for (int i=2; i<= N; i++){
        d[i][1] = max(d[i-2][1], d[i-2][2]) + arr[i];
        d[i][2] = d[i-1][1] + arr[i];
        //cout << i <<  "번째 : "<< "2칸 = "<< d[i][1] << ", 1칸 = " << d[i][2] <<'\n';
    }

    cout << *max_element(d[N],d[N]+3);

    return 0;
}
