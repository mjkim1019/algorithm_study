#include <iostream>
#include <list>
using namespace std;

int main(){
  int n;
  cin >> n;
  while (n--) {
    string s;
    list<char> L;
    auto cur = L.begin();
    
    cin >> s;
    
    for (char i: s){
      if (i == '<'){
        if (cur != L.begin()) cur--;
      } else if (i == '>') {
        if (cur != L.end()) cur++;
      } else if (i == '-'){
        if (cur != L.begin()) {
          cur--;
          cur = L.erase(cur);
        }
      } else {
        L.insert(cur, i);
      }
    }

    for (auto i : L)
      cout << i;
    cout << '\n';
  }

  return 0;
}
