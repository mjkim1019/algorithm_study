#include <iostream>
using namespace std;

int N;
int ans = 0;
bool isUsed1[16];
bool isUsed2[35];
bool isUsed3[35];

// L이 행
void func(int L)
{
    if (L == N)
    {
        ans++;
        return;
    }

    for (int j = 0; j < N; j++) // (L, j) 칸에 Q 놓을 예정
    {
        // 열, 대각선 오른쪽 위, 대각선 오른쪽 아래 가능한지 check
        if (isUsed1[j] || isUsed2[L + j] || isUsed3[L - j + N - 1])
            continue;

        isUsed1[j] = true;
        isUsed2[L + j] = true;
        isUsed3[L - j + N - 1] = true;
        func(L + 1);
        isUsed1[j] = false;
        isUsed2[L + j] = false;
        isUsed3[L - j + N - 1] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    func(0);
    cout << ans;

    return 0;
}
