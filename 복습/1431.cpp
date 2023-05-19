#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool cmp(const string & s1, const string &s2){
    if (s1.size() != s2.size()) return s1.size() < s2.size();
    int sum1 = 0, sum2 = 0;
    for (char c: s1){
        if (isdigit(c)) sum1 += c-'0';
    }
    for (char c : s2){
        if (isdigit(c)) sum2 += c - '0';
    }
    if (sum1 == sum2) return s1 < s2;
    else return sum1 < sum2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<string> v(N);
    for (int i=0; i<N; i++) cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    for (string &s: v) cout << s <<'\n';

    return 0;
}
