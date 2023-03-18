#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m;
deque<int> DQ;
int ans=0;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    DQ.push_back(i);

  for (int i=0; i<m; i++) {
    int tmp;
    cin >> tmp;
    int idx = find(DQ.begin(), DQ.end(), tmp) - DQ.begin();
    while (idx != 0) {
      ans++;
      if (idx <= DQ.size()/2) {
        int value = DQ.front();
        DQ.push_back(value);
        DQ.pop_front();
        idx--;
      } else {
        int value = DQ.back();
        DQ.push_front(value);
        DQ.pop_back();
        idx++;
        if (idx == DQ.size()) idx = 0;
      }
    }
    DQ.pop_front();
  }

  cout << ans;
  

  return 0;
}
