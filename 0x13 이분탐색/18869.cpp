#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;

    int M, N;
    cin >> M >> N;
    vector<int> arr[101];
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            int tmp; cin >> tmp;
            arr[i].push_back(tmp);
        }
    }

    vector<int> brute(M, 1);
    fill(brute.begin(), brute.begin()+2, 0);
    do{
        vector<int> idx;
        for (int i=0; i<M; i++) {
            if (idx.size() == 2) break;
            if (brute[i] == 0){
                idx.push_back(i);
            }
        }
        
        bool isValid = true;
        for (int i=0; i<N; i++){
            if (!isValid) break;
            for (int j=i+1; j<N; j++){
                if (arr[idx[0]][i] < arr[idx[0]][j] && arr[idx[1]][i] < arr[idx[1]][j]) continue;
                else if (arr[idx[0]][i] == arr[idx[0]][j] && arr[idx[1]][i] == arr[idx[1]][j]) continue;
                else if (arr[idx[0]][i] > arr[idx[0]][j] && arr[idx[1]][i] > arr[idx[1]][j]) continue;
                else {
                    isValid = false;
                    break;
                }
            }
        }
        if (isValid) answer++;
    }while (next_permutation(brute.begin(), brute.end()));

    cout << answer;

    return 0;
}
