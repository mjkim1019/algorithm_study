#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<int> two;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            two.push_back(arr[i] + arr[j]);
        }
    }

    sort(two.begin(), two.end());
    for (int i= N-1; i>0; i--){
        for (int j=0; j<i; j++){
            if (binary_search(two.begin(), two.end(), arr[i]-arr[j])){
                cout << arr[i]; return 0;
            }
        }
    }


    return 0;
}
