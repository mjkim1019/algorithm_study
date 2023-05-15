#include <iostream>
#include <vector>
using namespace std;

#define X first
#define Y second

int N;
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<pair<int, int> > v(N); // {end time, start time}
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(b, a); // end time 기준으로 정렬하기 위해
    }
    sort(v.begin(), v.end());

    int t = 0; 
    for (int i=0; i<N; i++){
        auto timestamp = v[i];
        if (t > timestamp.Y) continue;
        t = timestamp.X; 
        ans++;
    }
    
    cout << ans;

    return 0;
}
