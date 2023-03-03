#include <iostream>
#include <list>
using namespace std;

int main(){
  string s;
  list<char> L;
  int n;
  list<char>::iterator cur = L.begin();

  cin >> s;
  cin >> n;
  for (auto i: s) L.push_back(i);
  cur = L.end();
  while (n-->0) {
    char cmd, alp;
    cin >> cmd;

    if (cmd == 'P') {
      cin >> alp;
      L.insert(cur, alp);
    } else if (cmd == 'L') {
      if (cur != L.begin()) cur--;
    } else if (cmd == 'D'){
      if (cur != L.end()) cur++;
    } else if (cmd == 'B') {
      if (cur != L.begin()) {
        --cur;
        cur = L.erase(cur);
      }
    }
  }

  for (auto i: L) cout << i;

  return 0;
}
