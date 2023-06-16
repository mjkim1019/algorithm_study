#include <iostream>
#include <string>
#include <vector>
using namespace std;

char mem[20][10]; // 16 * 8

string solution(vector<string> &v)
{
    string ans;

    int i = 0, j = 0;
    for (string &cmd : v)
    {
        i += j / 8;
        j %= 8;
        cout << cmd << ' ';
        int sp = 0;
        if (cmd == "BOOL")
        {
            cout << "(" << i << ", " << j << ")" << '\t';
            mem[i][j] = '#';
            j += 1;
            cout << "(" << i << ", " << j << ")" << '\n';
            continue;
        }
        else if (cmd == "SHORT")
        {
            sp = 2;
            if ((j + sp) % 2 != 0)
            {
                while ((j + sp) % 2 != 0 && j < 8)
                {
                    mem[i][j] = '.';
                    j++;
                    if (j == 8) {j=0; i++;}
                }
            }
        }
        else if (cmd == "FLOAT")
        {
            sp = 4;
            while ((j + sp) % 4 != 0)
            {
                mem[i][j] = '.';
                j++;
                if (j == 8)
                {
                    j = 0;
                    i++;
                }
            }
        }
        else if (cmd == "INT")
        {
            sp = 8;
            while (j != 0)
            {
                mem[i][j] = '.';
                j++;
                if (j == 8)
                {
                    j = 0;
                    i++;
                }
            }
        }
        else if (cmd == "LONG")
        {
            sp = 16;
            if (j != 0)
            {
                while (j != 0)
                {
                    mem[i][j++] = '.';
                    j %= 8;
                }
                i++;
            }
            for (int k=0; k<2; k++)
                for (int m=0; m<8; m++) mem[i+k][m] = '#';
            i += 2;
            if (i >= 16)
                return "HALT";
            continue;
        }

        cout << "(" << i << ", " << j << ")" << '\t';
        int cnt = 0;
        while (cnt++<sp){
            mem[i][j%8] = '#';
            j++;
            if (j==8) i++;
        }
        j %= 8;
        cout << "(" << i << ", " << j << ")" << '\n';

        if (i >= 16) return "HALT";
    }

    for (int k = 0; k <= i; k++)
    {
        if (k == i)
        {
            if (j == 0) break;
            cout << ",";
            for (int m = 0; m < j; m++)
                cout << mem[k][m];
            for (int m = j; j < 8; j++)
                cout << '.';
            break;
        }
        for (int m = 0; m < 8; m++)
        {
            cout << mem[k][m];
        }
        if (k != i-1) cout << ",";
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v;
    v.push_back("BOOL");
    v.push_back("LONG");
    v.push_back("SHORT");
    v.push_back("LONG");
    v.push_back("BOOL");
    v.push_back("LONG");
    v.push_back("BOOL");
    v.push_back("LONG");
    v.push_back("BOOL");
    v.push_back("LONG");
    v.push_back("SHORT");
    v.push_back("LONG");
    v.push_back("LONG");

    cout << solution(v);

    return 0;
}
