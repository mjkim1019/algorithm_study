#include <iostream>
#include <string>

using namespace std;

int Q[100001];
int head = 0, tail = 0;

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    string cmd;
    cin >> cmd;
    if (cmd == "push")
    {
      int num;
      cin >> num;
      Q[tail++] = num;
    }
    else if (cmd == "pop")
    {
      if (head == tail)
        cout << "-1\n";
      else
        cout << Q[head++] << '\n';
    }
    else if (cmd == "size")
    {
      cout << tail - head << '\n';
    }
    else if (cmd == "empty")
    {
      cout << (head == tail) << '\n';
    }
    else if (cmd == "front")
    {
      if (head == tail)
        cout << "-1\n";
      else
        cout << Q[head] << '\n';
    }
    else if (cmd == "back")
    {
      if (head == tail)
        cout << "-1\n";
      else
        cout << Q[tail - 1] << '\n';
    }
  }

  return 0;
}
