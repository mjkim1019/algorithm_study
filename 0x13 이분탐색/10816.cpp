#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> answer;

    int N, M;
    cin >> N;
    vector<int> arr(N);
    for (int i=0; i<N; i++) 
        cin >> arr[i];
      
    sort(arr.begin(), arr.end());

    cin >> M;
    for (int i=0; i<M; i++){
        int tmp;
        cin >> tmp;
        answer.push_back(upper_bound(arr.begin(), arr.end(), tmp) - lower_bound(arr.begin(), arr.end(), tmp));
    }
    
    for (int i=0; i<answer.size(); i++) {
        cout << answer[i];
        if (i != answer.size()-1) cout << ' ';
    }

    return 0;
}
