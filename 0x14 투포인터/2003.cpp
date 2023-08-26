#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer=0;

    int N, M;
    cin >> N >> M;
    vector<int> arr(N+1); 
    int tmp;
    for (int i=1; i <=N; i++){
        cin >> tmp;
        arr[i] = arr[i-1]+tmp;
    }

    int l=0, r=0;
    while (r <= N){
        ll sum = arr[r]- arr[l];
        if (sum < M) r++;
        else {
            if (sum == M) answer++;
            l++;
        }
    }
    cout << answer;

    return 0;
}
