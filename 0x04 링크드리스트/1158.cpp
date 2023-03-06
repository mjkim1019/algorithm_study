#include <iostream>
#include <list>
#include <vector>

using namespace std;

int pre[5001];
int nxt[5001];
int n, k, len;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;

  // 원형연결리스트 생성
  for (int i=1; i<=n; i++) {
    pre[i] = (i==1)? n : i-1;
    nxt[i] = (i==n) ? 1 : i+1;
    ++len;
  }

  int i=1;
  for (int t=1; len !=0; t=nxt[t]) {
    // K번째 제거
    if (i==k) {
      pre[nxt[t]] = pre[t];
      nxt[pre[t]] = nxt[t];
      v.push_back(t);
      len--;
      i = 1;
    } else i++;
  }

  // 요세푸스 순열 출력
  cout << "<";
  for (int i=0; i< v.size(); i++){
    cout << v[i];
    if (i != v.size()-1) cout << ", ";
  }
  cout <<">";

  return 0;
}
