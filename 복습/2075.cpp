#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int tmp;
    cin >> N;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> tmp;
            pq.push(tmp);
            if (pq.size() > N) pq.pop();
        }
    }
    cout << pq.top();

    return 0;
}
