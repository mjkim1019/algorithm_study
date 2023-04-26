#include <iostream>
#include <queue>
using namespace std;

int n, w, L;

int bridge[105];
queue<int> truck;

int ans = 0; // 시간

bool isComplete(){ // 다리가 비었는지 확인
    for (int i=0; i<w; i++){
        if (bridge[i]>0) return false;
    }
    return true;
}

void move(){
    for (int i=w-1; i>0; i--)
        bridge[i] = bridge[i-1];
    bridge[0] = 0;
}

int calculate(){ // 현재 다리위의 트럭들 무게
    int sum = 0;
    for (int i=0; i<w; i++)
        sum += bridge[i];
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> w >> L;
    for (int i=0; i<n; i++) {
        int t;
        cin >> t;
        truck.push(t);
    }
    
    
    do{
        int tmp = calculate();
        if (tmp <= L)
        {
            tmp -= bridge[w-1];
            move();
            if (!truck.empty() && (truck.front() + tmp <= L)){
                bridge[0] = truck.front(); truck.pop();
            }
        }
        ans++;
    } while(!isComplete());

    cout << ans;

    return 0;
}
