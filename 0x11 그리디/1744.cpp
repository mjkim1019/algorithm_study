#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(vector<int> &v){
    int ans = 0;
    if (v.size() < 2)
    {
        for (int &i : v) ans += i;
    }
    else
    {
        for (int i = 1; i < v.size(); i += 2)
            ans += v[i] * v[i - 1];
        
        if (v.size() % 2 == 1)
            ans += v[v.size() - 1];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;

    int N;
    cin >> N;
    vector<int> plus, minus;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == 1) ans += tmp;
        else if (tmp > 0) plus.push_back(tmp);
        else minus.push_back(tmp);
    }
    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());

    
    ans += sum(plus);
    ans += sum(minus);
    
    cout << ans;

    return 0;
}
