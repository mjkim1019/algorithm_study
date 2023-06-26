#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dist[200005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    for (int i=0; i<=100000; i++) dist[i] = -1;

    queue<int> Q;
    Q.push(N);
    dist[N] = 0;
    while (!Q.empty()){
        int cur = Q.front(); Q.pop();

        if (cur == K) {
            cout << dist[K];
            return 0;
        }
        
        if (dist[cur+1] == -1){
            Q.push(cur+1);
            dist[cur+1] = dist[cur]+1;
        }
        if (cur-1 >=0 && dist[cur-1] == -1){
            Q.push(cur-1);
            dist[cur-1] = dist[cur]+1;
        }
        if (cur*2 <= 2000000 && dist[cur*2] == -1){
            Q.push(cur*2);
            dist[cur*2] = dist[cur]+1;
        }
    }

    return 0;
}
