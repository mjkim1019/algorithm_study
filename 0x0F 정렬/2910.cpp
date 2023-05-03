#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> C;
    vector<pair<int, int> > arr; // {번호, 빈도}
    vector<bool> v(C+1);
    while (N--){
        int num;
        cin >> num;
        if (v[num]){
           for (auto &item: arr){
                if (item.first == num) {
                    item.second++;
                    break;
                }
           }
        } else {
            arr.push_back(make_pair(num, 1));
            v[num] = true;
        }
    }


    stable_sort(arr.begin(), arr.end(), cmp);
    for (auto item: arr){
        for (int i=0; i<item.second; i++)
            cout << item.first << ' ';
    }


    return 0;
}
