#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<pair<int, int> > jewel(N); // 자동으로 정렬됨
    for (int i = 0; i < N; i++)
        cin >> jewel[i].Y >> jewel[i].X; // 가격, 무게 순으로 입력받음
    sort(jewel.begin(), jewel.end(), greater<>());

    multiset<int> bags;
    for (int i = 0; i < K; i++)
    {
        int tmp;
        cin >> tmp;
        bags.insert(tmp);
    }

    long long answer = 0;
    for (int i = 0; i < N; i++)
    {
        if (bags.empty()) break;
        auto it = bags.lower_bound(jewel[i].Y);
        if (it == bags.end()) continue;
        answer += jewel[i].X;
        bags.erase(it);
    }
    cout << answer;

    return 0;
}
