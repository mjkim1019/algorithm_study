#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, len;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;

  queue<int> Q;
  for (int i=1; i<=n; i++){
    Q.push(i);
  }

  int t = 1;
  while (!Q.empty()) {
    int temp = Q.front();
    if (t == k){
      v.push_back(temp);
      Q.pop();
      t = 1;
    } else {
      Q.push(temp);
      Q.pop();
      t++;
    }
  }
  
  cout << '<';
  for (int i=0; i<v.size(); i++){
    if (i != v.size()-1) cout << v[i] << ", ";
    else cout << v[i];
  }
  cout << '>';
 
}
