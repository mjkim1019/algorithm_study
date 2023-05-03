#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;

bool cmp(string &s1, string &s2){
    if (s1.size() != s2.size()) return s1.size() < s2.size();
    return s1 < s2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<string> arr(n);
    for (int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end(), cmp);

    // arr.erase(unique(arr.begin(), arr.end()), arr.end()); 중복제거

    string str = "";
    for (string s: arr){
        if (str != s)
            cout << s << '\n';
        str = s;
    }

    return 0;
}
