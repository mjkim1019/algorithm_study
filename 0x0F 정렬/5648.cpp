#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<string> arr(n);
    for (int i=0; i<n; i++)
        cin >> arr[i];

    vector<long long> numArr;
    for (string &s: arr){
        reverse(s.begin(), s.end());
        numArr.push_back(stoull(s));
    }
    sort(numArr.begin(), numArr.end());
    for (long long i: numArr) cout << i << '\n';

    return 0;
}
