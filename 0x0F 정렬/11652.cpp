#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int N;
ll mxval = -(1ll<< 62) -1;
int mxcnt = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> input;
    cin >> N;
    while (N--){
        ll tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    sort(input.begin(), input.end());

    mxval = input[0];
    int cnt = 1;
    for (int i=1; i<input.size(); i++){
        if (input[i] == input[i-1]) cnt++;
        else {
            if (mxcnt < cnt){
                mxcnt = cnt;
                mxval = input[i-1];
            }
            cnt = 1;
        }
    }
    if (mxcnt < cnt) mxval = input[input.size()-1];

    cout << mxval;


    return 0;
}
