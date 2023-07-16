#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    unordered_map<string, string> um;

    while (N--){
        string s1, s2;
        cin >> s1 >> s2;
        um[s1] = s2;
    }

    while (M--){
        string url;
        cin >> url;
        cout << um[url] <<'\n';
    }

    return 0;
}
