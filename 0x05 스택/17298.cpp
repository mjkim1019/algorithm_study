#include <iostream>
#include <stack>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int arr[1000001];
  int n;
  stack<pair<int, int> > S;
  cin >> n;

  for (int i=1; i<=n; i++) {
    arr[i] = -1;
  }

  S.push(make_pair(1000001, 0));
  for (int i=1; i<=n; i++) {
    int num;
    cin >> num;
    while (S.top().first < num) {
      arr[S.top().second] = num;
      S.pop();
    }
    S.push(make_pair(num, i));
  }

  for (int i=1; i<=n; i++) cout << arr[i] <<" ";

  return 0;
}
