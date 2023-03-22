#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string cmd;
        int n;
        string str_arr;
        deque<int> DQ;
        bool isReversed = false;
        bool isError = false;
        cin >> cmd >> n >> str_arr;

        // 덱에 배열 넣기
        for (int i=0; i<str_arr.size(); i++){
            str_arr[i];
            if (str_arr[i] == '[' || str_arr[i] == ']' || str_arr[i] == ',') str_arr[i]=' ';
        }
        stringstream ss;
        ss.str(str_arr);
        int num;
        while(ss >> num) DQ.push_back(num);
        
        for (char c: cmd) {
            if (c == 'R') {
                isReversed = !isReversed;
            } else if (c == 'D') {
                if (DQ.empty()) {
                    isError = true; break;
                }
                if (isReversed) {
                    DQ.pop_back();
                } else {
                    DQ.pop_front();
                }
            }
        }
        if (isError){
            cout << "error\n"; continue;
        }

        cout << '[';
        if (isReversed)
        {
            while (!DQ.empty())
            {
                cout << DQ.back();
                if (DQ.size() != 1) cout << ',';
                DQ.pop_back();
            }
        }
        else
        {
            while (!DQ.empty())
            {
                cout << DQ.front();
                if (DQ.size() != 1) cout << ',';
                DQ.pop_front();
            }
        }
        cout << "]\n";
        getchar();
    }


    return 0;
}
