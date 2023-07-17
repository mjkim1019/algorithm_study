#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
    unordered_map<string, int> dress; // 의상종류, 개수
    int N; cin >> N;
    while (N--){
        string str1, str2;
        cin >> str1 >> str2;
        dress[str2]++;
    }

    int answer = 1;
    for (auto d: dress){
        answer *= d.second+1;
    }
    cout << answer-1 <<'\n';
    }

    return 0;
}
