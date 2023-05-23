#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int &a, int &b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> plus;
    vector<int> minus;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp > 0)
            plus.push_back(tmp);
        else
            minus.push_back(tmp);
    }
    sort(plus.begin(), plus.end(), cmp);
    sort(minus.begin(), minus.end());

    int ans = 0;
    if (plus.size() < 2)
    {
        for (int &i : plus) ans += i;
    }
    else
    {
        for (int i = 1; i < plus.size(); i += 2)
        {
            if (plus[i] >= 2 && plus[i - 1] >= 2)
                ans += plus[i] * plus[i - 1];
            else
                ans += plus[i] + plus[i - 1];
        }
        if (plus.size() %2 == 1) ans += plus[plus.size()-1];
    }

    if (minus.size() < 2){
        for (int &i: minus) ans += i;
    } else {
        for (int i=1; i<minus.size(); i+=2) {
            ans += minus[i] * minus[i-1];
        }
        if (minus.size() %2 == 1) ans += minus[minus.size()-1];
    }
    cout << ans;

    return 0;
}
