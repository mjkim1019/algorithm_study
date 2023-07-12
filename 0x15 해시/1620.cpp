#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    string numbers[100001];
    unordered_map<string, int> names;
    for (int i=1; i<=N; i++){
        string str;
        cin >> str;
        numbers[i] = str;
        names[str] = i;
    }

    while (M--){
        string str;
        cin >> str;
        if (isdigit(str[0])) cout << numbers[stoi(str)] << '\n';
        else cout << names[str] <<'\n';
    }
    

    return 0;
}
