#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> Q;
    answer++;
    int i=0;
    int sum = truck_weights[0];
    Q.push(truck_weights[i++]);
    while (!Q.empty() && i < truck_weights.size()){
        answer++;
        //cout << i << '\n';
    
        if (Q.size() == bridge_length) {
            sum -= Q.front(); 
            Q.pop();
        }
    
        if (sum + truck_weights[i] <= weight){
            //cout << answer <<'\n';
            sum += truck_weights[i];
            Q.push(truck_weights[i++]);
        } else {
            Q.push(0);
        }
    }
    
    answer += bridge_length;
    
    return answer;
}
