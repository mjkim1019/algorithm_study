#include <iostream>
#include <algorithm>
using namespace std;

int answer = 0;
int N;
int board[21][21];
int test[21][21];

void push(){
    int nboard[21][21];
    for (int i=0; i<21; i++) fill(nboard[i], nboard[i]+21, 0);
    for (int i=0; i<N; i++){
        int pos=0;
        for (int j=0; j<N; j++){
            if (test[i][j] == 0) continue;
            if (nboard[i][pos] == 0) nboard[i][pos] = test[i][j];
            else if (nboard[i][pos] != test[i][j]) nboard[i][++pos] = test[i][j];
            else nboard[i][pos++] *=2;
        }
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            test[i][j] = nboard[i][j];
        }
    }
}

void rotate(int dir) {
    while (dir--)
    {
        int tmp[21][21];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                tmp[i][j] = test[i][j];
                
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                test[i][j] = tmp[N-j-1][i];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> board[i][j];
    
    for (int tmp=0; tmp< 1<<(2*5); tmp++){
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                test[i][j] = board[i][j];

        int brute = tmp;
        for (int i=0; i<5; i++){
            int dir = brute %4;
            brute /= 4;

            rotate(dir);
            push();
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                answer = max(answer, test[i][j]);
    }
    cout << answer;

    return 0;
}
