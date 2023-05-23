#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long ans = 0;

    stack<int> Sd, Sp;
    for (int i=0; i<n; i++){
        Sd.push(deliveries[i]);
        Sp.push(pickups[i]);
    }

    while(!Sd.empty() || !Sp.empty()){
        while(!Sd.empty() && Sd.top() == 0) Sd.pop();
        while(!Sp.empty() && Sp.top() == 0) Sp.pop();
        ans += max(Sd.size(), Sp.size())*2;
        //cout << Sd.size() << ' ' << Sp.size() <<'\n';

        int rest = cap;
        while (rest>0 && !Sd.empty()){
            int cnt = Sd.top(); Sd.pop();
            if (rest >= cnt) rest -= cnt;
            else {
                Sd.push(cnt - rest);
                rest = 0;
            }
        }

        rest = cap;
        while (rest>0 && !Sp.empty()){
            int cnt = Sp.top(); Sp.pop();
            if (rest >= cnt) rest -= cnt;
            else {
                Sp.push(cnt - rest);
                rest = 0;
            }
        }
    }


    return ans;
}
