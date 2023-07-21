#include <iostream>
#include <queue>
using namespace std;

class cmp{
    public:
    bool operator()(int a, int b){
        return a > b;
    };
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    priority_queue<int, vector<int>, cmp> pq;
    while (N--){
        int x; cin >> x;
        if (x == 0){
            if (pq.empty()) {
                cout << 0 <<'\n';
            }else {
            cout << pq.top() << '\n';
            pq.pop();
            }
        } else pq.push(x);
        
    }

    return 0;
}
