#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    int n; 
    cin >> n;
    if (n ==0) return 0;
    stack<pair<int, int> > S;
    long long ans = 0;
    for (int i=0; i<n; i++) {
      int h;
      cin >> h;
      int idx = i;
      while (!S.empty() && S.top().first >= h) {
        long long area = 1LL * (i-S.top().second) * S.top().first;
        ans = max(area, ans);
        idx = S.top().second; // 현재의 직사각형(h)과 이전의 모든 직사각형(S.top().X)을 포함하는 직사각형의 넓이를 계산하기 위해
        S.pop();
      }
      S.push(make_pair(h, idx));
    }
    while (!S.empty()) {
      long long area = 1LL * (n - S.top().second) * S.top().first;
      ans = max(area, ans);
      S.pop();
    }
    cout << ans <<'\n';
  }

  return 0;
}
