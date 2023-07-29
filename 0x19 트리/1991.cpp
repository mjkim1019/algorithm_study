#include <iostream>
#include <queue>
using namespace std;

int lc[30];
int rc[30];

void preorder(int cur){
    cout << (char)(cur+'A'-1);
    if (lc[cur]) preorder(lc[cur]);
    if (rc[cur]) preorder(rc[cur]);
}

void inorder(int cur){
    if (lc[cur]) inorder(lc[cur]);
    cout << (char)(cur + 'A'-1);
    if (rc[cur]) inorder(rc[cur]);
}

void postorder(int cur){
    if (lc[cur]) postorder(lc[cur]);
    if (rc[cur]) postorder(rc[cur]);
    cout << (char)(cur + 'A'-1);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--){
        char a, b, c;
        cin >> a >> b >> c;
        if (b != '.') lc[a-'A'+1] = b-'A'+1; // 1부터 시작하도록
        if (c != '.') rc[a-'A'+1] = c-'A'+1;
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);

    return 0;
}
