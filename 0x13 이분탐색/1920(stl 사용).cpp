#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;
    for (int i=0; i<N; i++) cin >> a[i];
    sort(a, a+N);
    cin >> M;
    for (int i=0; i<M; i++){
        int n;
        cin >> n;
        cout << binary_search(a, a+N, n) <<'\n';
    }

    return 0;
}
