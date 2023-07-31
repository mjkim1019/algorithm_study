#include <iostream>
using namespace std;

int d[1000001];
int pre[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    d[1] = 0;
    for (int k=2; k<=N; k++){
        d[k] = d[k-1]+1;
        pre[k] = k-1;
        if (k%2 == 0 && d[k] > d[k/2]+1) {
            d[k] = d[k/2]+1;
            pre[k] = k/2;
        }
        if (k%3 == 0 && d[k] > d[k/3]+1) {
            d[k] = d[k/3]+1;
            pre[k] =k/3;
        }
    }
    
    cout << d[N] <<'\n';
    while (N>=1){
        cout << N << ' ';
        N = pre[N];
    }
    

    return 0;   
}
