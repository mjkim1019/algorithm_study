#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;

    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i=0; i<N; i++){
        int tmp; cin >> tmp;
        pq.push(tmp);
    }

    while (pq.size() >= 1){
        int a = pq.top(); pq.pop();
        if (pq.empty()) break;
        int b = pq.top(); pq.pop();
        answer += a+b;
        if (pq.empty()) break;
        pq.push(a+b);
    }
    cout << answer;

    return 0;
}
