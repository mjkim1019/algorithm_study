#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<string> v;

bool cmp(const string &s1, const string &s2)
{
    if (s1.size() != s2.size())
        return s1.size() < s2.size();

    int sum1 = 0;
    for (const char &c : s1)
    {
        if (c >= '0' && c <= '9') sum1 += c - '0';
    }
    int sum2 = 0;
    for (const char &c : s2)
    {
        if (c >= '0' && c <= '9')sum2 += c - '0';
    }
    if (sum1 != sum2) return sum1 < sum2;

    return s1 < s2;   
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (N--)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);
    for (string &s : v)
    {
        cout << s << '\n';
    }

    return 0;
}
