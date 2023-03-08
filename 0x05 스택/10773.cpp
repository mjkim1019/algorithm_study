#include <iostream>
#include <stack>

using namespace std;

int main(){
  stack<int> S;
  int k;
  cin >> k;

  while (k--) {
    int n;
    cin >> n;
    if (n == 0) S.pop();
    else S.push(n);
  }

  int sum = 0;
  while (!S.empty()) {
    sum += S.top();
    S.pop();
  }
  cout << sum ;

  return 0;
}
