#include <iostream>
#include <string>

using namespace std;

int dict[26];

int main() {
    string word;
    
    cin >> word;

    for (char c: word){
        dict[c-'a']++;
    }

    for (int i: dict){
        cout << i << ' ';
    }

    return 0;
}
