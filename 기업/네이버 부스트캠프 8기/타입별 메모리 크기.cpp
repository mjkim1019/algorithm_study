#include <iostream>
#include <string>
#include <vector>
using namespace std;

//패딩 먼저 채우고 자리 옮긴 후 자기 크기만큼 하면 #로 채우기
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
            mem[i][j] = '#';
            j += 1;
        }
        else if (cmd == "SHORT")
        {
            while (j %2 != 0){
                mem[i][j] = '.';
                j++;
                if (j == 8) {i+=1; j=0;}
            }
            for (int k=0; k<2; k++) mem[i][j+k] = '#';
            j += 2;
        }
        else if (cmd == "FLOAT")
        {
            while (j %4 != 0){
                mem[i][j] = '.';
                j++;
                if (j==8) {i++; j=0;}
            }
            for (int k=0; k<4; k++) mem[i][j+k] = '#';
            j += 4;
        }
        else if (cmd == "INT")
        {
            sp = 8;
            while (j != 0)
            {
                mem[i][j] = '.';
                j++;
                if (j == 8){ i++; j=0; }
            }
            for (int k = 0; k < 8; k++) mem[i][j + k] = '#';
            i++;
        }
        else if (cmd == "LONG")
        {
            sp = 16;

            while (j != 0)
            {
                mem[i][j] = '.';
                j++;
                if (j == 8) {i++; j = 0;}
            }

            for (int k=0; k<2; k++)
                for (int m=0; m<8; m++) mem[i+k][m] = '#';
            i += 2;
        }
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
    v.push_back("FLOAT");
    v.push_back("SHORT");
    v.push_back("BOOL");
    v.push_back("BOOL");
    v.push_back("BOOL");
    v.push_back("INT");

    cout << solution(v);

    return 0;
}
