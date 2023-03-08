#include <iostream>
#include <string>

using namespace std;

int main()
{
  int stk[10001];
  int pos = 0;
  int n;
  
  cin >> n;
  while (n--)
  {
    string cmd;
    cin >> cmd;
    if (cmd == "push")
    {
      int temp;
      cin >> temp;
      stk[pos++] = temp;
    }
    if (cmd == "pop")
    {
      if (pos != 0){
        cout << stk[--pos] <<'\n';
      }
      else
        cout << "-1\n";
    }
    if (cmd == "size")
    {
      cout << pos << '\n';
    }
    if (cmd == "empty")
    {
      if (pos == 0)
        cout << "1\n";
      else
        cout << "0\n";
    }
    if (cmd == "top")
    {
      if (pos >= 1)
      {
        cout << stk[pos - 1] << '\n';
      }
      else
        cout << "-1\n";
    }
  }

  return 0;
}
