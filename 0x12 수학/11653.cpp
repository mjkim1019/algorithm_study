#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n){
    vector<int> answer;
    for (int i=2; i*i<=n; i++){
        if (n == 1) break;
        while (n % i == 0) {
            answer.push_back(i);
            n /= i;
        }
    }
    if (n != 1) answer.push_back(n);
    return answer;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    if (N == 1) return 0;
    vector<int> arr = solution(N);
    for (auto a: arr ) cout << a << '\n';
    return 0;
}
