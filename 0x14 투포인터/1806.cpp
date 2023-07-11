#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, S;
    cin >> N >> S;
  
    vector<int> d(N+1);
    d[0] = 0;
    for (int i=1; i<=N; i++) {
        int tmp;
        cin >> tmp;
        d[i] = d[i-1]+tmp;
    }

    int answer = N+1;
    int en = 0;
    for (int st=0; st<=N; st++){
        while (en <= N && d[en]-d[st] < S) en++;
        if (en == N+1) break;
        //cout << en << " - " << st << '\n';
        answer = min(answer, en-st);
    }
    if (answer == N+1) cout << 0;
    else cout << answer;

    return 0;
}
