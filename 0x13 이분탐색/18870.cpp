#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> uni;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
        uni.push_back(arr[i]);
    }

    sort(uni.begin(), uni.end());
    // 중복 제거
    // vector<int> uni;
    // uni.push_back(brute[0]);
    // for (int i=1; i<brute.size(); i++){
    //     if (brute[i-1] == brute[i]) continue;
    //     uni.push_back(brute[i]);
    // }
    uni.erase(unique(uni.begin(), uni.end()), uni.end());

    for (int i=0; i<arr.size(); i++){
        cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin();
        if (i != arr.size()-1) cout <<' ';
    }



    return 0;
}
