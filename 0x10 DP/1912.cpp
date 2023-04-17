#include <iostream>
#include <algorithm>
using namespace std;

int d[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> d[i]; // 반드시 한 개 이상 수를 선택해야하므로 

    for (int k=2; k<=n; k++){
        d[k] = max(d[k-1], 0) + d[k];
    }
    cout << *max_element(d+1, d+n+1);


    
    return 0;
}
