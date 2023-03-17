#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> DQ;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--)
  {
    string cmd;
    cin >> cmd;

    if (cmd == "push_front")
    {
      int temp;
      cin >> temp;
      DQ.push_front(temp);
    }
    else if (cmd == "push_back")
    {
      int temp;
      cin >> temp;
      DQ.push_back(temp);
    }
    else if (cmd == "pop_front")
    {
      if (DQ.empty())
        cout << "-1\n";
      else
      {
        cout << DQ.front() << '\n';
        DQ.pop_front();
      }
    }
    else if (cmd == "pop_back")
    {
      if (DQ.empty())
        cout << "-1\n";
      else
      {
        cout << DQ.back() << '\n';
        DQ.pop_back();
      }
    }
    else if (cmd == "size")
    {
      cout << DQ.size() << '\n';
    }
    else if (cmd == "empty")
    {
      cout << DQ.empty() << '\n';
    }
    else if (cmd == "front")
    {
      if (DQ.empty())
        cout << "-1\n";
      else
      {
        cout << DQ.front() << '\n';
      }
    }
    else if (cmd == "back")
    {
      if (DQ.empty())
        cout << "-1\n";
      else
      {
        cout << DQ.back() << '\n';
      }
    }
  }

  return 0;
}
