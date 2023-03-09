#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;
string ans;
stack<int> S;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  S.push(0);
  cin >> N;
  int k = 1;
  while (N--)
  {
    int num;
    cin >> num;
    while (k <= num)
    {
      S.push(k++);
      ans += "+\n";
    }
    if (S.top() != num)
    {
      cout << "NO\n";
      return 0;
    }
    S.pop();
    ans += "-\n";
  }

  cout << ans;

  return 0;
}
