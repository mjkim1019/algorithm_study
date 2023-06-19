#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr){
    int ans = 0;

    vector<int> a = arr;
    while (ans < 10){
        if (a.size() == 1) return ans+1;
        for (int val: a) cout << val << ' ';
        vector<int> v;
        int cnt = 1;
        for (int i=1; i<a.size(); i++){
            if (a[i] != a[i-1]){
                v.push_back(cnt);
                cnt = 1;
            }
            else cnt++; 
        }
        v.push_back(cnt);
        a = v;
        cout << '\n';
        ans++;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //vector<int> arr = {1, 1, 3, 3, 2, 2, 4, 5, 1, 1, 1, 3, 3, 3};
    //vector<int> arr = {1, 2, 3};
    vector<int> arr = {2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 2, 1, 2};
    cout << solution(arr);

    return 0;
}
