#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int>> v){
    vector<int> ans(2);

    // solution 1
    for (int i=0; i<2; i++){
        if (v[0][i] == v[1][i]) ans[i] = v[2][i];
        else if (v[0][i] == v[2][i]) ans[i] = v[1][i];
        else if (v[1][i] == v[2][i]) ans[i] = v[0][i];
    }

    // solution 2
    // ^xor : 두 수가 같으면 0, 다르면 1 반환 
    // 무조건 두 값은 같으므로 0이 되므로, 다른 값 하나만 도출됨
    for (int i=0; i<2; i++){
        ans[i] = v[0][i]^v[1][i]^v[2][i];
    }

    return ans;
}
