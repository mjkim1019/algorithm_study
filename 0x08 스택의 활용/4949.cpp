#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        string str;
        getline(cin, str);
        if (str == ".") return 0;

        stack<char> S;
        bool isYes = true;
        for (char c : str)
        {
            if (c == '(' || c == '[') S.push(c);
            if (c == ')')
            {
                if (S.empty() || S.top() != '(') {
                    isYes = false; break;
                }
                S.pop();
            }
            if (c == ']')
            {
                if (S.empty() || S.top() != '[')
                {
                    isYes = false;
                    break;
                }
                S.pop();   
            }
        }
        if (!S.empty()) isYes = false;
        if (isYes) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
