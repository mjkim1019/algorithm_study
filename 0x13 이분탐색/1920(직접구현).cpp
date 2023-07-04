#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[100001];

bool binary_search(int st, int en, int val){
    while (st <=en){
        int mid = (st + en) / 2;
        if (a[mid] == val) return true;
        else if (a[mid] < val) st = mid+1;
        else en = mid -1;
    }
    return false;
}

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
        cout << binary_search(0, N-1, n) <<'\n';
    }

    return 0;
}
