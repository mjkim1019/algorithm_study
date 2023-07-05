#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> answer;

    int N, M;
    cin >> N;
    vector<int> arr(N);
    unordered_map<int, int> mp;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    cin >> M;
    for (int i=0; i<M; i++){
        int tmp;
        cin >> tmp;
        if (binary_search(arr.begin(), arr.end(), tmp)) answer.push_back(mp[tmp]);
        else answer.push_back(0);
    }
    
    for (int i=0; i<answer.size(); i++) {
        cout << answer[i];
        if (i != answer.size()-1) cout << ' ';
    }

    return 0;
}
