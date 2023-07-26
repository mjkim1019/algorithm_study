#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<>> pq; // 최소힙
    int N;
    cin >> N;
    for (int i=0; i<N*N; i++){
        int tmp;
        cin >> tmp;
        pq.push(tmp);
        if (pq.size() > N) pq.pop(); // 상위 5개만 큐에 남겨놓기
    }

    cout << pq.top();

    return 0;
}
