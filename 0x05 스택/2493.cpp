#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  string ans;
  int n;
  cin >> n;

  stack<pair<int, int>> S;
  S.push(make_pair(100000001, 0));
  for (int i=1; i<= n; i++){
    int height;
    cin >> height;
    
    while(S.top().first < height) S.pop();
    ans += to_string(S.top().second) + " ";
    S.push(make_pair(height, i));
  }

  cout << ans;

  return 0;
}
