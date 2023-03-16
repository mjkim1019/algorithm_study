#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long ans = 0;
  int n;
  cin >> n;

  stack<pair<int,int>> S;
  while (n--)
  {
    int height;
    cin >> height;
    int cnt = 1;
    while (!S.empty() && S.top().first <= height) {
      ans += S.top().second;
      if (S.top().first == height) cnt += S.top().second;
      S.pop();
    }
    if (!S.empty()) ans++;
    S.push({height, cnt});
  }
  cout << ans;

  return 0;
}
