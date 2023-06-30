#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001][3];
int d[1001][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    for (int i=0; i<3; i++) d[0][i] = arr[0][i];
    for (int i=1; i<=N; i++){
        for (int k=0; k<3; k++){
            d[i][k] = min(d[i-1][(k+1)%3], d[i-1][(k+2)%3]) + arr[i][k];
        }
    }

    cout << *min_element(d[N], d[N]+3);

    return 0;
}
