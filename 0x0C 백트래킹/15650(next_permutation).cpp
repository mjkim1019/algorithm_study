#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<int> brute(N, 1);
    fill(brute.begin(), brute.begin()+M, 0);
    do{
        for (int i=0; i<N; i++)
            if (brute[i] == 0) cout << i+1 << ' ';
        
        cout << '\n';
    }while (next_permutation(brute.begin(), brute.end()));

    
    return 0;
}
