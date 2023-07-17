#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class cmp {
public:
    bool operator()(int a, int b){ // 최대힙이 default이므로 반대로 생각
        if (abs(a) == abs(b)) return a > 0 && b < 0;
        return abs(a) > abs(b); 
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    priority_queue<int, vector<int>, cmp> PQ;
    while (N--){
        int n; 
        cin >> n;
        if (n != 0) PQ.push(n);
        else {
            if (PQ.empty()) {
                cout << 0 <<'\n';
                continue;
            }
            cout << PQ.top() <<'\n';
            PQ.pop();
        }
    }

    return 0;
}
