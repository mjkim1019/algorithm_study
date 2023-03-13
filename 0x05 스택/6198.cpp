#include <iostream>
#include <stack>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long ans =0;
  int n;
  cin >> n;
  stack<int> S;
  while (n--) {
    int height;
    cin >> height;

    while (!S.empty() && S.top() <= height) S.pop();
    ans += S.size();
    S.push(height);
  } 
  cout << ans;
 
  return 0;
}
