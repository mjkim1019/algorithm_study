#include <iostream>
#include <stack>

using namespace std;

int main()
{
  stack<int> S;
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
      S.push(temp);
    }
    else if (cmd == "pop")
    {
      if (!S.empty())
      {
        cout << S.top() << '\n';
        S.pop();
      }
      else
        cout << "-1\n";
    }
    else if (cmd == "size")
    {
      cout << S.size() << '\n';
    }
    else if (cmd == "empty")
    {
      cout << S.empty() << '\n';
    }
    else if (cmd == "top")
    {
      if (!S.empty())
        cout << S.top() << '\n';
      else
        cout << "-1\n";
    }
  }

  return 0;
}
