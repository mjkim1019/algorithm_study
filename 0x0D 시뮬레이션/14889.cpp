#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int s[22][22];
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            cin >> s[i][j];
    
    ans = 100*N/2; 

    vector<bool> num(N);
    fill(num.begin()+(N/2), num.end(), true);
    do{
        vector<int> start;
        vector<int> link;
        for (int i=0; i<N; i++){
            if (num[i]) start.push_back(i+1);
            else link.push_back(i+1);
        }
        
        int s_ability = 0;
        for (int i=0; i<start.size(); i++)
            for (int j=0; j<start.size(); j++)
                s_ability += s[start[i]][start[j]];
            
        int l_ability = 0;
        for (int i = 0; i < link.size(); i++)
            for (int j = 0; j < link.size(); j++)
                l_ability += s[link[i]][link[j]];

        ans = min(ans, abs(s_ability-l_ability));

    }while(next_permutation(num.begin(), num.end()));

    cout << ans;

    return 0;
}
