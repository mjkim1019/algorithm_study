#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<string> solution(string p1, int cntmask){
    vector<string> ans;
    vector<unsigned char> address;

    for (int i=0; i<p1.size(); i++) if (p1[i] == '.') p1[i] = ' ';
    stringstream ss(p1);
    unsigned char num;
    while (ss >> num) address.push_back(num);

    

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a = "192.20.0.1";
    int n = 8;
    
    solution(a, n);

    return 0;
}
